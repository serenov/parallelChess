#pragma once

#include "./structs/core.types.h"

void playMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);
// void undoMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);


// inline utility functions 

void initBitboards(Bitboards* bitboard);
void setBitOnBitboard(Bitboard *b, Square s);
void clearBitOnBitboard(Bitboard *b, Square s);
