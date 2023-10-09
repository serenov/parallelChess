#pragma once

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
    case BLACK_PAWN:
        return &(bitboards->blackPawns);
    }

    return 0;
}

inline Square firstBit(Bitboard *board)
{
    Square square = __builtin_ctzll(board);

    *board &= ~(1UL << square);

    return square;
}

