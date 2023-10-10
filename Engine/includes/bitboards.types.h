#pragma once

#include <stdint.h>


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
