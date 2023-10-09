#pragma once

#include <stdbool.h>


typedef enum {

    BLACK,
    WHITE,
    NO_COLOR

} Color;


typedef enum {

    WHITE_KING = 'K',
    WHITE_QUEEN = 'Q',
    WHITE_ROOK = 'R',
    WHITE_BISHOP = 'B',
    WHITE_PAWN = 'P',
    BLACK_KING = 'k',
    BLACK_QUEEN = 'q',
    BLACK_ROOK = 'r',
    BLACK_BISHOP = 'b',
    BLACK_PAWN = 'p',
    NULL_PIECE = ' '

} Piece;



inline Color getColorByPiece(Piece p){

    if(p == NULL_PIECE) return NO_COLOR;

    if(p > WHITE_PAWN) return BLACK;

    return WHITE;
}

