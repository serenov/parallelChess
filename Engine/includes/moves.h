#pragma once

#include "boards.h"
#include "squares.h"
#include "pieces.h"

typedef enum 
{
    BLAND,
    PAWN_MOVE,
    CAPTURE,
    ENPASSANT_W,
    ENPASSANT_B,
    CASTLE_W_LEFT,
    CASTLE_W_RIGHT,
    CASTLE_B_LEFT,
    CASTLE_B_RIGHT,
    PROMOTION_W_P,
    PROMOTION_W_N,
    PROMOTION_W_B,
    PROMOTION_W_R,
    PROMOTION_W_Q,
    PROMOTION_B_P,
    PROMOTION_B_N,
    PROMOTION_B_B,
    PROMOTION_B_R,
    PROMOTION_B_Q
} Movetype;

typedef struct 
{

    Square from;
    Square to;

} Move;


typedef struct 
{
    
    Square from;
    Square to;

    Movetype type;

} MoveInfo;

// Move dispatchers

// Move* moveConstructor(Boards* boards, Square from, Square to);
// bool pushMove(Boards* boards, Move* move);
// bool popMove(Boards* boards);

// Move Generators

// Bitboard getMoves(Boards* boards, Piece piece, Square square);

// static inline Bitboard generateKingMoves(Boards* boards, Square square);
// static inline Bitboard generateKnightMoves(Boards* boards, Square square);
// static inline Bitboard generateQueenMoves(Boards* boards, Square square);
// static inline Bitboard generateRookMoves(Boards* boards, Square square);
// static inline Bitboard generateBishopMoves(Boards* boards, Square square);
// static inline Bitboard generatePawnMoves(Boards* boards, Square square);

inline Bitboard generateLegalMoves(Boards* boards, Square square);