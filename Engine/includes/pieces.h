#pragma once

#include <stdbool.h>


typedef enum {

    black,
    white,
    noColor

} Color;


typedef enum {

    whiteKing = 'K',
    whiteQueen = 'Q',
    whiteRook = 'R',
    whiteBishop = 'B',
    whitePawn = 'P',
    blackKing = 'k',
    blackQueen = 'q',
    blackRook = 'r',
    blackBishop = 'b',
    blackPawn = 'p',
    nullPiece = ' '

} Piece;



inline Color getColorByPiece(Piece p){

    if(p == nullPiece) return noColor;

    if(p > whitePawn) return black;

    return white;
}

