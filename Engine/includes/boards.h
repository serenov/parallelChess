#pragma once

#include <stdbool.h>

#include "bitboards.h"
#include "pieces.h"
#include "moves.h"
#include "squares.h"
#include "board.h"

#define DEFAULT_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

typedef Square* SquaresList;


typedef struct {

    bool canCastleRight[2];
    bool canCastleLeft[2];

    Square Enpassant;

    bool checkmate;
    bool stalemate;

    Color colorToPlay;

    MoveInfo movesHistory[1000];

} BoardState;


typedef struct {

    PlainBoard board;
    Bitboards bitboards;
    BoardState state;

} Boards;


void initBoards(Boards* boards, char* fenString);

void playMoveOnBoards(Boards* boards, Move* move);
void undoMoveOnBoards(Boards* boards, Move* move);

// Inline utilities

inline static void putPieceOnSquare(PlainBoard board, Piece piece, Square square);
inline static void removePieceOnSquare(PlainBoard board, Square square);

// Move Generation Functions

// static inline Bitboard generateKingMoves(Square square);
// static inline Bitboard generateKnightMoves(Square square);
// static inline Bitboard generateQueenMoves(Square square);
// static inline Bitboard generateRookMoves(Square square);
// static inline Bitboard generateBishopMoves(Square square);
// static inline Bitboard generatePawnMoves(Square square);