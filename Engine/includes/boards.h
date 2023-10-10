#pragma once

#include <stdbool.h>

#include "bitboards.h"
#include "pieces.h"
#include "moves.h"
#include "squares.h"
#include "board.h"
#include "magicBoards.h"
#define DEFAULT_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

#define MAX_NUMBER_OF_MOVES 1000

typedef Square* SquaresList;


typedef enum 

{
    RUNNING,
    STALEMATE,
    CHEKCMATE,
    BLACK_RESIGN,
    WHITE_RESIGN,
    DRAW_BY_REP,
    DRAW_BY_50

} GameStatus;


typedef struct 
{
    bool canCastleRight[2];
    bool canCastleLeft[2];

    Square Enpassant;

    GameStatus status;

    Color colorToPlay;

    MoveInfo movesHistory[MAX_NUMBER_OF_MOVES];

} BoardState;


typedef struct 
{

    PlainBoard board;
    Bitboards bitboards;
    BoardState state;

} Boards;


void initBoards(Boards* boards, char* fenString);

void playMoveOnBoards(Boards* boards, Move* move);
void undoMoveOnBoards(Boards* boards, Move* move);

void generateLegalMoves(Boards* boards, Square from);

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

inline Bitboard pawnAttackPattern(Boards* boards, Color c, Square from) 
{
    return (c == WHITE)? 
        ((1UL << (from + 7)) | (1UL << (from + 9))) & (boards -> bitboards.blackPieces):
        ((1UL << (from - 7)) | (1UL << (from - 9))) & (boards -> bitboards.whitePieces);
}


inline Bitboard pawnMoveGeneralPattern(Boards* boards, Color c, Square from)
{
    Bitboard move = (c == WHITE)? 1UL << (from + 8): 1UL << (from - 8);
    return move & ~(boards -> bitboards.occupiedBoard); 
}
