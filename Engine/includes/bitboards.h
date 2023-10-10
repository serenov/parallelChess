#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "squares.h"
#include "pieces.h"
#include "moves.h"

typedef char byte;



typedef uint64_t Bitboard;


typedef struct {

    Bitboard whitePawns;
    Bitboard blackPawns;

    Bitboard whiteKnights;
    Bitboard blackKnights;

    Bitboard whiteBishops;
    Bitboard blackBishops;

    Bitboard whiteRooks;
    Bitboard blackRooks;

    Bitboard whiteQueens;
    Bitboard blackQueens;

    Bitboard whiteKing;
    Bitboard blackKing;

    Bitboard blackPieces;
    Bitboard whitePieces;

    Bitboard occupiedBoard;
    Bitboard occupiedRotated90LBoard;
    Bitboard occupiedRotated45LBoard;
    Bitboard occupiedRotated45RBoard;

} Bitboards;

inline void initBitboards(Bitboards* bitboard) {
    bitboard -> whitePawns = 0;
    bitboard -> blackPawns = 0;
    bitboard -> whiteKnights = 0;
    bitboard -> blackKnights = 0;
    bitboard -> whiteBishops = 0;
    bitboard -> blackBishops = 0;
    bitboard -> whiteRooks = 0;
    bitboard -> blackRooks = 0;
    bitboard -> whiteQueens = 0;
    bitboard -> blackQueens = 0;
    bitboard -> whiteKing = 0;
    bitboard -> blackKing = 0;
    bitboard -> blackPieces = 0;
    bitboard -> whitePieces = 0;
    bitboard -> occupiedBoard = 0;
    bitboard -> occupiedRotated90LBoard = 0;
    bitboard -> occupiedRotated45LBoard = 0;
    bitboard -> occupiedRotated45RBoard = 0;
}

void playMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);
// void undoMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);


// inline utility functions 

inline void setBitOnBitboard(Bitboard *b, Square s)
{
    const Bitboard mask = 1UL << s;

    *b |= mask;
}

inline void clearBitOnBitboard(Bitboard *b, Square s)
{
    const Bitboard mask = 1UL << s;

    *b &= ~mask;
}
