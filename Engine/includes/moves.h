#pragma once

#include "boards.h"
#include "squares.h"
#include "pieces.h"

#define MAX_MOVE_LENGTH 1056

typedef enum {

    CAPTURE,
    ENPASSANT,
    CASTLING,
    PROMOTION,
    Illegal

} Movetype;

typedef struct {

    Piece attackPiece;

    Square from;
    Square to;

    Movetype type;

    void* extraInformation;

} Move;

typedef Move* MovesList;

typedef struct {

    MovesList list[MAX_MOVE_LENGTH];
    int length;

} Moves;

typedef struct {

    Square from;
    Square to;

} CastleMoveInformation;

typedef struct {

    Square capturedAt;

} EnpassantInformation;

typedef struct {
    Piece capturedPiece;
} capturePieceInformation;



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