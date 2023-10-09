#include "includes/bitboards.h"
#include "includes/pieces.h"
#include "includes/magicBoards.h"



// void setPieceOnBitboards(Bitboards* bitboards, Square square, Piece piece){

//     Bitboard pickedSquare = A1Square << square;

//     const Bitboard* pickedBitboard = getBitboardForPiece(bitboards, piece);

//     setBitOnBitboard(pickedBitboard, square);

//     setBitOnBitboard(&(bitboards -> occupiedBoard), square);

//     setBitOnBitboard(&(bitboards -> occupiedRotated90LBoard), magicBoards.rotated90L[square]);

//     setBitOnBitboard(&(bitboards -> occupiedRotated45LBoard), magicBoards.leftwardLeaning[square].transformedIndex);

//     setBitOnBitboard(&(bitboards -> occupiedRotated45RBoard), magicBoards.rightwardLeaning[square].transformedIndex);

//     if(isWhite(piece)) setBitOnBitboard(&(bitboards -> whitePieces), square);
//     else setBitOnBitboard(&(bitboards -> blackPieces), square);

// }

// void clearPieceOnBitboards(Bitboards* bitboards, Square square, Piece piece) {

//     Bitboard pickedSquare = A1Square << square;

//     const Bitboard* pickedBitboard = getBitboardForPiece(bitboards, piece);

//     clearBitOnBitboard(pickedBitboard, square);

//     clearBitOnBitboard(&(bitboards -> occupiedBoard), square);

//     clearBitOnBitboard(&(bitboards -> occupiedRotated90LBoard), magicBoards.rotated90L[square]);

//     clearBitOnBitboard(&(bitboards -> occupiedRotated45LBoard), magicBoards.leftwardLeaning[square].transformedIndex);

//     clearBitOnBitboard(&(bitboards -> occupiedRotated45RBoard), magicBoards.rightwardLeaning[square].transformedIndex);

//     if(isWhite(piece)) clearBitOnBitboard(&(bitboards -> whitePieces), square);
//     else clearBitOnBitboard(&(bitboards -> blackPieces), square);

// }

void playMoveOnBitboards(Bitboards* bitboards, Move* move) {
    setPieceOnBitboards(bitboards, move -> to, move -> attackPiece);
    clearPieceOnBitboards(bitboards, move -> from, move -> attackPiece);
}


void undoMoveOnBitboards(Bitboards* bitboards, Move* move) {}


// Inline utilities

inline Bitboard* getBitboardForPiece(Bitboards* bitboards, Piece piece) {

    switch (piece) {
        case whiteKing:
            return &(bitboards->whiteKing);
        case whiteQueen:
            return &(bitboards->whiteQueens);
        case whiteRook:
            return &(bitboards->whiteRooks);
        case whiteBishop:
            return &(bitboards->whiteBishops);
        case whitePawn:
            return &(bitboards->whitePawns);
        case blackKing:
            return &(bitboards->blackKing);
        case blackQueen:
            return &(bitboards->blackQueens);
        case blackRook:
            return &(bitboards->blackRooks);
        case blackBishop:
            return &(bitboards->blackBishops);
        case blackPawn:
            return &(bitboards->blackPawns);
    }

    return 0;
}


inline static void setBitOnBitboard(Bitboard *b, Square s) {

    const Bitboard mask = A1Square << s;

    *b |= mask;

}

inline static void clearBitOnBitboard(Bitboard *b, Square s) {

    const Bitboard mask = A1Square << s;

    *b &= ~mask;
}

inline bool inBoundsPredicate(Square s) {

    if (s >= A1 && s <= H8) return true; 

    return false;

}

inline Square firstBit(Bitboard* board){
    #ifdef __clang__ || __GNUC__
       Square square =  __builtin_ctzll(board);
    #else
        // Fallback implementation for other compilers
        if (b == 0) {
            return -1; // No bits set
        }

        int count = 0;
        while ((b & 1) == 0) {
            b >>= 1;
            count++;
        }

        char position = count;
    #endif

    *board &= ~(1UL << square);

    return square;
}

// // Moves Generators

// #define LEFTRIGHT 65793UL
// #define UPMASK 7UL
// #define DOWNMASK 16140901064495857664UL
// #define DEKNIGHT_MASK 11529215046068469760UL
// #define DKNIGHT_MASK 9799832789158199296UL
// #define UKNIGHT_MASK 17UL
// #define UEKNIGHT_MASK 5UL


// static inline Bitboard generateKingMoves(Square square) {
//     if(!inBoundsPredicate(square)) return 0;

//     int x = square % 8, y = square / 8;

//     Bitboard movesGenerated = 0;

//     if(x > 0) {
//         //left
//         movesGenerated |= (y)? LEFTRIGHT << (square - 9):  LEFTRIGHT >> (9 - x);
//     }

//     if(x < 7) {
//         //right
//         movesGenerated |= (y)? LEFTRIGHT << (square - 7): LEFTRIGHT >> (7 - x);
//     }

//     if(y > 0) {
//         //down
//         movesGenerated |= (DOWNMASK >> (70 - square)) & magicBoards.ranks[y - 1];
//     }

//     if(y < 7) {
//         //up
//         movesGenerated |= (UPMASK << (square + 7)) & magicBoards.ranks[y + 1];
//     }

//     return movesGenerated;
// }

// static inline Bitboard generateKnightMoves(Square square) {
//     if(!inBoundsPredicate(square)) return 0;

//     int x = square % 8, y = square / 8;

//     Bitboard movesGenerated = 0;

//     if(y > 0){
//         // Downwards knight move
//         movesGenerated |= (DKNIGHT_MASK >> (69 - square)) & magicBoards.ranks[y - 1];
//     }

//     if(y > 1){
//         //Downward Extreme knight move
//         movesGenerated |= (DEKNIGHT_MASK >> (78 - square)) & magicBoards.ranks[y - 2];
//     }
  
//     if(y < 7){
//         //Upwards knight move
//         movesGenerated |= (UKNIGHT_MASK << (square + 6)) & magicBoards.ranks[y + 1];
//     }

//     if(y < 6){
//         //Upwards Extreme knight move
//         movesGenerated |= (UEKNIGHT_MASK << (square + 15)) & magicBoards.ranks[y + 2];
//     }

//     return movesGenerated;
// }

// static inline generateRookMoves(Bitboards* bitboards, Square square) {

//     Bitboard movesGenerated = 0;

//     //ranks

//     movesGenerated |= magicBoards.attackRank[square][getRankState(bitboards -> occupiedBoard, square)];

//     //files
    
//     movesGenerated |= magicBoards.attackFile[square][getFileState(bitboards -> occupiedRotated90LBoard, square)];

//     return movesGenerated;

// }

// static inline generateBishopMoves(Bitboards* bitboards, Square square) {
//     Bitboard movesGenerated = 0;
//     //Left diagonal
    
//     movesGenerated |= magicBoards.attackLeftDiagonal[square][getLeftDiagonalState(bitboards -> occupiedRotated45LBoard, square)];
    
//     //Right diagonal

//     movesGenerated |= magicBoards.attackRightDiagonal[square][getRightDiagonalState(bitboards -> occupiedRotated45RBoard, square)];

//     return movesGenerated;

// }

// static inline generatePawnMoves(Bitboards* bitboards, Square square){
    
// }

// Fetching states

// inline static int getRankState(Bitboard occupiedBoard, Square square) {
//     return (occupiedBoard >> (square / 8)) & 255;
// }

// inline static int getFileState(Bitboard occupiedRotated90L, Square square) {
//     return (occupiedRotated90L >> (square / 8)) & 255;
// }

// inline static int getRightDiagonalState(Bitboard occupiedRotated45R, Square square) {
//     int diagonalMask = (1 << (magicBoards.rightwardLeaning[square].lengthOfDiagonal - 1)) - 1; 
//     return (occupiedRotated45R >> magicBoards.rightwardLeaning[square].skip) & diagonalMask;
// }

// inline static int getLeftDiagonalState(Bitboard occupiedRotated45L, Square square) {
//     int diagonalMask = (1 << (magicBoards.leftwardLeaning[square].lengthOfDiagonal - 1)) - 1; 
//     return (occupiedRotated45L >> magicBoards.leftwardLeaning[square].skip) & diagonalMask;
// }



