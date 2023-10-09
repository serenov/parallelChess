#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "squares.h"
#include "pieces.h"
#include "moves.h"

typedef char byte;



typedef uint64_t Bitboard;
// typedef uint64_t PositionMask;

// a constant that represent A1 square on bitboard
const Bitboard A1Square = 1;
const Bitboard H8Square = 1 << 63;

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

void playMoveOnBitboards(Bitboards* bitboards, Move* move);
void undoMoveOnBitboards(Bitboards* bitboards, Move* move);

static void setPieceOnBitboards(Bitboards* bitboards, Square square, Piece piece);
static void clearPieceOnBitboards(Bitboards* bitboards, Square square, Piece piece);



// inline utility functions 

inline static void setBitOnBitboard(Bitboard *b, Square s);
inline static void clearBitOnBitboard(Bitboard *b, Square s);

inline Square popFirstBit(Bitboard* b);
inline Bitboard* getBitboardForPiece(Bitboards* bitboards, Piece piece);


// inline static int getFileState(Bitboard occupiedBoard);
// inline static int getRankState(Bitboard occupiedRotated90L);
// inline static int getRightDiagonalState(Bitboard occupiedRotated45R);
// inline static int getLeftDiagonalState(Bitboard occupiedRotated45L);
