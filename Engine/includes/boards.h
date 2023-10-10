#pragma once

#define DEFAULT_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

#include "core.types.h"




void initBoards(Boards *boards, char *fenString);
void initPlainBoard(PlainBoard pb);

void playMoveOnBoards(Boards* boards, Move* move);
void undoMoveOnBoards(Boards* boards, Move* move);

Bitboard generateLegalMoves(Boards* boards, Square from);

// Inline utilities

inline static void putPieceOnSquare(PlainBoard board, Piece piece, Square square);
inline static void removePieceOnSquare(PlainBoard board, Square square);

// Move Generation Functions

inline int getRankState(Boards *boards, Square square)
{
    return ((boards->bitboards.occupiedBoard) << __occupied_skip__[square]) & 255;
}
inline int getFileState(Boards *boards, Square square)
{
    return ((boards->bitboards.occupiedBoard) << __occupied90L_skip__[square]) & 255;
}
inline int getRDiagonal(Boards *boards, Square square)
{
    return ((boards->bitboards.occupiedBoard) << __occupied45R_skip__[square]) & ((1 << __occupied45R_diagonalLength__[square]) - 1);
}
inline int getLDiagonal(Boards *boards, Square square)
{
    return ((boards->bitboards.occupiedBoard) << __occupied45L_skip__[square]) & ((1 << __occupied45L_diagonalLength__[square]) - 1);
}


inline Bitboard generateRookMoves(Boards *boards, Square from) 
{
    return 
    __attackRank__[from][getRankState(boards, from)] |
    __attackFile__[from][getFileState(boards, from)];
}

inline Bitboard generateBishopMoves(Boards *boards, Square from) 
{
    return 
    __attackLeftDiagonal__[from][getLDiagonal(boards, from)] |
    __attackRightDiagonal__[from][getRDiagonal(boards, from)];
}

inline Bitboard pawnAttackPattern(Boards* boards, Square from) 
{
    const Bitboard enpassant = 1UL << (boards -> state.Enpassant);
    return (boards -> state.colorToPlay == WHITE)? 
        ((1UL << (from + 7)) | (1UL << (from + 9))) & (boards -> bitboards.blackPieces) & enpassant:
        ((1UL << (from - 7)) | (1UL << (from - 9))) & (boards -> bitboards.whitePieces) & enpassant;
}


inline Bitboard pawnMoveGeneralPattern(Boards* boards, Square from)
{
    Color c = boards -> state.colorToPlay;

    Bitboard move = (c == WHITE)? 1UL << (from + 8): 1UL << (from - 8);
    move &= ~(boards -> bitboards.occupiedBoard);

    if((from / 8) == 1 || (from / 8) == 6)
    {
        Bitboard initialMove = (c == WHITE)? 1UL << (from + 16): 1UL << (from - 16);
        move |=  (move)? (initialMove & ~(boards -> bitboards.occupiedBoard)): 0;
    }
    return move; 
}
