#include "../includes/bitboards.h"
#include "../includes/utils.h"

inline void initBitboards(Bitboards* bitboard) 
{
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

void playMoveOnBitboards(Bitboards *bitboards, Move *move, Piece movingPiece)
{
    Bitboard* targetBitboard = getBitboardForPiece(bitboards, movingPiece);

    setBitOnBitboard(targetBitboard, move -> from);
    clearBitOnBitboard(targetBitboard, move -> to);

    Bitboard* clrBitboard = 
        (getColorByPiece(movingPiece) == WHITE)? 
            &(bitboards -> whitePieces): 
            &(bitboards -> blackPieces);

    setBitOnBitboard(clrBitboard, move -> from);
    clearBitOnBitboard(clrBitboard, move -> to);

    int toTrans = __occupied90L_shift__[move -> from];
    int fromTrans = __occupied90L_shift__[move -> to];

    Bitboard* occupied90L = &(bitboards -> occupiedRotated90LBoard);
    setBitOnBitboard(occupied90L, move -> from);
    clearBitOnBitboard(occupied90L, move -> to);

    toTrans = __occupied45L_shift__[move -> from];
    fromTrans = __occupied45L_shift__[move -> to];

    Bitboard* occupied45L = &(bitboards -> occupiedRotated45LBoard);
    setBitOnBitboard(occupied45L, move -> from);
    clearBitOnBitboard(occupied45L, move -> to);

    toTrans = __occupied45R_shift__[move -> from];
    fromTrans = __occupied45R_shift__[move -> to];

    Bitboard* occupied45R = &(bitboards -> occupiedRotated45RBoard);
    setBitOnBitboard(occupied45R, move -> from);
    clearBitOnBitboard(occupied45R, move -> to);
}

// void undoMoveOnBitboards(Bitboards *bitboards, Move *move)
// {
// }

// Inline utilities





inline bool inBoundsPredicate(Square s)
{
    if (s >= A1 && s <= H8)
        return true;

    return false;
}

