#pragma once

#include "bitboards.types.h"

// Magic Boards for rotated 45 degrees board
unsigned char __occupied45R_shift__[64] = {
    35, 27, 20, 14,  9,  5,  2,  0, 
    42, 34, 26, 19, 13,  8,  4,  1, 
    48, 41, 33, 25, 18, 12,  7,  3, 
    53, 47, 40, 32, 24, 17, 11,  6, 
    57, 52, 46, 39, 31, 23, 16, 10, 
    60, 56, 51, 45, 38, 30, 22, 15, 
    62, 59, 55, 50, 44, 37, 29, 21, 
    63, 61, 58, 54, 49, 43, 36, 28
};

const unsigned char __occupied45R_diagonalLength__[64] = {
    8, 7, 6, 5, 4, 3, 2, 1, 
    7, 8, 7, 6, 5, 4, 3, 2, 
    6, 7, 8, 7, 6, 5, 4, 3, 
    5, 6, 7, 8, 7, 6, 5, 4, 
    4, 5, 6, 7, 8, 7, 6, 5, 
    3, 4, 5, 6, 7, 8, 7, 6, 
    2, 3, 4, 5, 6, 7, 8, 7, 
    1, 2, 3, 4, 5, 6, 7, 8
};

const unsigned char __occupied45R_skip__[64] = {
    28, 21, 15, 10,  6,  3,  1,  0,
    36, 28, 21, 15, 10,  6,  3,  1,
    43, 36, 28, 21, 15, 10,  6,  3,
    49, 43, 36, 28, 21, 15, 10,  6,
    54, 49, 43, 36, 28, 21, 15, 10,
    58, 54, 49, 43, 36, 28, 21, 15,
    61, 58, 54, 49, 43, 36, 28, 21,
    63, 61, 58, 54, 49, 43, 36, 28 
};



// Magic Boards for rotated 45 degrees board
unsigned char __occupied45L_shift__[64] = {
     0,  2,  5,  9, 14, 20, 27, 35, 
     1,  4,  8, 13, 19, 26, 34, 42, 
     3,  7, 12, 18, 25, 33, 41, 48, 
     6, 11, 17, 24, 32, 40, 47, 53, 
    10, 16, 23, 31, 39, 46, 52, 57, 
    15, 22, 30, 38, 45, 51, 56, 60, 
    21, 29, 37, 44, 50, 55, 59, 62, 
    28, 36, 43, 49, 54, 58, 61, 63
};

const unsigned char __occupied45L_diagonalLength__[64] = {
    1, 2, 3, 4, 5, 6, 7, 8, 
    2, 3, 4, 5, 6, 7, 8, 7, 
    3, 4, 5, 6, 7, 8, 7, 6, 
    4, 5, 6, 7, 8, 7, 6, 5, 
    5, 6, 7, 8, 7, 6, 5, 4, 
    6, 7, 8, 7, 6, 5, 4, 3, 
    7, 8, 7, 6, 5, 4, 3, 2, 
    8, 7, 6, 5, 4, 3, 2, 1
};

unsigned char __occupied45L_skip__[64] = {
     0,  1,  3,  6, 10, 15, 21, 28, 
     1,  3,  6, 10, 15, 21, 28, 36, 
     3,  6, 10, 15, 21, 28, 36, 43, 
     6, 10, 15, 21, 28, 36, 43, 49, 
    10, 15, 21, 28, 36, 43, 49, 54, 
    15, 21, 28, 36, 43, 49, 54, 58, 
    21, 28, 36, 43, 49, 54, 58, 61, 
    28, 36, 43, 49, 54, 58, 61, 63
};


// magic Board for rotated 90 Degrees Board

const unsigned char __occupied90L_shift__[64] = {
    7, 15, 23, 31, 39, 47, 55, 63, 
    6, 14, 22, 30, 38, 46, 54, 62, 
    5, 13, 21, 29, 37, 45, 53, 61, 
    4, 12, 20, 28, 36, 44, 52, 60, 
    3, 11, 19, 27, 35, 43, 51, 59, 
    2, 10, 18, 26, 34, 42, 50, 58, 
    1,  9, 17, 25, 33, 41, 49, 57, 
    0,  8, 16, 24, 32, 40, 48, 56
};

unsigned char __occupied90L_skip__[64] = {
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56,
    0, 8, 16, 24, 32, 40, 48, 56
};

// magic board for 0 Degrees Board

unsigned char __occupied_skip__[64] = {
     0,  0,  0,  0,  0,  0,  0,  0,
     8,  8,  8,  8,  8,  8,  8,  8,
    16, 16, 16, 16, 16, 16, 16, 16,
    24, 24, 24, 24, 24, 24, 24, 24,
    32, 32, 32, 32, 32, 32, 32, 32,
    40, 40, 40, 40, 40, 40, 40, 40,
    48, 48, 48, 48, 48, 48, 48, 48,
    56, 56, 56, 56, 56, 56, 56, 56
};  

// attack patterns for pieces

Bitboard __kingAttack__[64];
Bitboard __knightAttack__[64];
Bitboard __pawnAttack__[2][64];
Bitboard __attackRank__[64][256];
Bitboard __attackFile__[64][256];
Bitboard __attackRightDiagonal__[64][256];
Bitboard __attackLeftDiagonal__[64][256];


// ranks & files
Bitboard __ranks__[8];
Bitboard __files__[8];

// Initializationss


// static inline void initKnightAttack();
// static inline void initKingAttack();
// static inline void initAttackRank();
// static inline void initAttackFile();
// static inline void initAttackRightDiagonal(); 
// static inline void initAttackLeftDiagonal();

// static inline void initRanksAndFiles();