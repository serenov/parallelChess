#pragma once

#include "core.types.h"

void playMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);
// void undoMoveOnBitboards(Bitboards* bitboards, Move* move, Piece movingPiece);


// inline utility functions 

inline void initBitboards(Bitboards* bitboard);
inline void setBitOnBitboard(Bitboard *b, Square s);
inline void clearBitOnBitboard(Bitboard *b, Square s);
