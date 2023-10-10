#pragma once
#include "core.types.h"

inline Bitboard* getBitboardForPiece(Bitboards *bitboards, Piece piece)
{
    switch (piece)
    {
    case WHITE_KING:
        return &(bitboards->whiteKing);
    case WHITE_QUEEN:
        return &(bitboards->whiteQueens);
    case WHITE_ROOK:
        return &(bitboards->whiteRooks);
    case WHITE_BISHOP:
        return &(bitboards->whiteBishops);
    case WHITE_KNIGHT:
        return &(bitboards->blackBishops);
    case WHITE_PAWN:
        return &(bitboards->whitePawns);
    case BLACK_KING:
        return &(bitboards->blackKing);
    case BLACK_QUEEN:
        return &(bitboards->blackQueens);
    case BLACK_ROOK:
        return &(bitboards->blackRooks);
    case BLACK_BISHOP:
        return &(bitboards->blackBishops);
    case BLACK_KNIGHT:
        return &(bitboards->blackBishops);
    case BLACK_PAWN:
        return &(bitboards->blackPawns);

    default: 
        
    }

    return 0;
}

inline Square firstBit(Bitboard *board)
{
    Square square = __builtin_ctzll(*board);

    *board &= ~(1UL << square);

    return square;
}


inline Piece parsePiece(char c) 
{
    switch(c) {
    case 'K':
        return WHITE_KING;
    case 'Q':
        return WHITE_QUEEN;
    case 'R':
        return  WHITE_ROOK;
    case 'B':
        return  WHITE_BISHOP;
    case 'N':
        return  WHITE_KNIGHT;
    case 'P':
        return  WHITE_PAWN;
    case 'k':
        return  BLACK_KING;
    case 'q':
        return  BLACK_QUEEN;
    case 'r':
        return  BLACK_ROOK;
    case 'b':
        return  BLACK_BISHOP;
    case 'n':
        return  BLACK_KNIGHT;
    case 'p':
        return  BLACK_PAWN;
    default: 
        return NULL_PIECE;
    }
}

inline Color getColorByPiece(Piece p){

    if(p == NULL_PIECE) return NO_COLOR;

    if(p > WHITE_PAWN) return BLACK;

    return WHITE;
}