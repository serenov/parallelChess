#include "../includes/magicBoards.h"

static inline void initPawnAttacks()
{
    const Bitboard fileA = __files__[0], fileH = __files__[7]; for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1)) { __pawnAttack__[WHITE][sq] = 0;
        __pawnAttack__[BLACK][sq] = 0;

        Bitboard p = 1UL << sq;

        if (~fileA & p)
        {
            __pawnAttack__[WHITE][sq] |= p << 7;
            __pawnAttack__[BLACK][sq] |= p >> 9;
        }

        if (~fileH & p)
        {
            __pawnAttack__[WHITE][sq] |= p << 9;
            __pawnAttack__[BLACK][sq] |= p >> 7;
        }
    }
}

static inline void initKnightAttack()
{
    const Bitboard fileA = __files__[0], fileH = __files__[7];
    const Bitboard fileAB = __files__[1] | fileA, fileGH = __files__[6] | fileH;

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        Bitboard p = 1UL << sq;

        __knightAttack__[sq] = 0;

        if (~fileA & p)
        {
            __knightAttack__[sq] |= p << 15;
            __knightAttack__[sq] |= p >> 17;
        }

        if (~fileAB & p)
        {
            __knightAttack__[sq] |= p << 6;
            __knightAttack__[sq] |= p >> 10;
        }

        if (~fileH & p)
        {
            __knightAttack__[sq] |= p << 17;
            __knightAttack__[sq] |= p >> 15;
        }

        if (~fileGH & p)
        {
            __knightAttack__[sq] |= p << 10;
            __knightAttack__[sq] |= p >> 6;
        }
    }
}

static inline void initKingAttack()
{
    const Bitboard fileA = __files__[0], fileH = __files__[7];
    // const Bitboard rank1 = __ranks__[0], rank8 = __ranks__[7];

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        __kingAttack__[sq] = 0;

        Bitboard p = 1UL << sq;

        __kingAttack__[sq] |= p << 8;
        __kingAttack__[sq] |= p >> 8;

        if (~fileA & p)
        {
            __kingAttack__[sq] |= p << 7;
            __kingAttack__[sq] |= p >> 1;
            __kingAttack__[sq] |= p >> 9;
        }

        if (~fileH & p)
        {
            __kingAttack__[sq] |= p >> 7;
            __kingAttack__[sq] |= p << 1;
            __kingAttack__[sq] |= p << 9;
        }
    }
}

static inline void initAttackRank()
{

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        int x = sq % 8, y = sq / 8;

        Bitboard p = 1UL << sq;

        unsigned char start = 1 << x;

        for (unsigned char state = 1; state < 256; state++)
        {
            __attackRank__[sq][state] = 0;

            for (int i = 1; i <= x; i++)
            {
                __attackRank__[sq][state] |= p >> i;
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i <= 7 - x; i++)
            {
                __attackRank__[sq][state] |= p << i;
                if ((start << i) & state)
                    break;
            }
        }
    }
}

static inline void initAttackFile()
{
    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        Bitboard p = 1UL << sq;

        int x = sq % 8, y = sq / 8;

        for (unsigned char state = 1; state < 256; state++)
        {
            __attackFile__[sq][state] = 0;

            unsigned char start = 1 << y;

            for (int i = 1; i <= y; i++)
            {
                __attackFile__[sq][state] |= p >> (i * 8);
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i <= 7 - y; i++)
            {
                __attackFile__[sq][state] |= p << (i * 8);
                if ((start << i) & state)
                    break;
            }
        }
    }
}

static inline void initAttackRightDiagonal()
{
    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        Bitboard pos = 1UL << sq;

        int limit = 1 << (__occupied45R_diagonalLength__[sq]);

        unsigned char start = 1 << (__occupied45L_shift__[sq] - __occupied45R_skip__[sq]);

        for (unsigned char state = 1; state < limit; state++)
        {
            __attackRightDiagonal__[sq][state] = 0;

            for (int i = 1; i <= (__occupied45L_shift__[sq] - __occupied45R_skip__[sq]); i++)
            {
                __attackRightDiagonal__[sq][state] |= pos << (i * 9);
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i < ((__occupied45R_skip__[sq] + __occupied45R_diagonalLength__[sq]) - __occupied45R_shift__[sq]); i++)
            {
                __attackRightDiagonal__[sq][state] |= pos >> (i * 9);
                if ((start << i) & state)
                    break;
            }
        }
    }
}

static inline void initAttackLeftDiagonal()
{
    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        Bitboard pos = 1UL << sq;

        int limit = 1 << __occupied45L_diagonalLength__[sq];

        unsigned char start = 1 << (__occupied45L_shift__[sq] - __occupied45L_skip__[sq]);

        for (unsigned char state = 1; state < limit; state++)
        {
            __attackLeftDiagonal__[sq][state] = 0;

            for (int i = 1; i <= (__occupied45L_shift__[sq] - __occupied45L_skip__[sq]); i++)
            {
                __attackLeftDiagonal__[sq][state] |= pos << (i * 7);
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i < ((__occupied45L_skip__[sq] + __occupied45L_diagonalLength__[sq]) - __occupied45L_shift__[sq]); i++)
            {
                __attackLeftDiagonal__[sq][state] |= pos >> (i * 7);
                if ((start << i) & state)
                    break;
            }
        }
    }
}

static inline void initRanksAndFiles()
{
    for (int i = 0; i < 8; i++)
    {
        __ranks__[i] = 255UL << i * 8;
        __files__[i] = 72340172838076673UL << i * 8;
    }
}


void initMagicBoards()
{
    initRanksAndFiles();
    initKingAttack();
    initKnightAttack();

    initAttackRank();
    initAttackFile();

    initAttackLeftDiagonal();
    initAttackRightDiagonal();
}
