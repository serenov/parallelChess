#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef unsigned short byte;

typedef uint64_t Bitboard;
typedef uint64_t PositionMask;

// a constant that represent A1 square on bitboard
const PositionMask A1Square = 1;
const PositionMask H8Square = 1UL << 63;

typedef enum
{

    A1,
    B1,
    C1,
    D1,
    E1,
    F1,
    G1,
    H1,
    A2,
    B2,
    C2,
    D2,
    E2,
    F2,
    G2,
    H2,
    A3,
    B3,
    C3,
    D3,
    E3,
    F3,
    G3,
    H3,
    A4,
    B4,
    C4,
    D4,
    E4,
    F4,
    G4,
    H4,
    A5,
    B5,
    C5,
    D5,
    E5,
    F5,
    G5,
    H5,
    A6,
    B6,
    C6,
    D6,
    E6,
    F6,
    G6,
    H6,
    A7,
    B7,
    C7,
    D7,
    E7,
    F7,
    G7,
    H7,
    A8,
    B8,
    C8,
    D8,
    E8,
    F8,
    G8,
    H8,
    null

} Square;

typedef struct
{

    Bitboard whitePawns;
    Bitboard blackPawns;

    Bitboard whiteKnights;
    Bitboard blackKnights;

    Bitboard whiteBishops;
    Bitboard blackBishops;

    Bitboard whiteRooks;
    Bitboard blackRooks;

    Bitboard whiteQueens;
    Bitboard blackQueens;

    Bitboard whiteKing;
    Bitboard blackKing;

    Bitboard blackPieces;
    Bitboard whitePieces;

    Bitboard occupiedBoard;
    Bitboard occupiedRotated90LBoard;
    Bitboard occupiedRotated45LBoard;
    Bitboard occupiedRotated45RBoard;

} Bitboards;

typedef byte Statemask;

typedef struct
{

    // To save space...

    byte transformedIndex;
    byte lengthOfDiagonal;
    byte skip;

} transformed45;

typedef byte transformed90Indices[64];
typedef transformed45 transformed45Indices[64];

static struct MagicBoards
{

    Bitboard attackRank[64][256];
    Bitboard attackFile[64][256];

    Bitboard attackRightDiagonal[64][256];
    Bitboard attackLeftDiagonal[64][256];

    // Extra information about the rotated boards

    transformed45Indices leftwardLeaning;
    transformed45Indices rightwardLeaning;
    transformed90Indices rotated90L;

    Bitboard ranks[8];
    Bitboard files[8];

} magicBoards;

void displayBitboard(uint64_t b)
{

    PositionMask pos = A1Square;

    for (int y = 7; y > -1; y--)
    {

        printf("\n -------------------------------\n");
        for (int x = 0; x < 8; x++)
        {

            char c = ((pos << (y * 8 + x)) & b) ? '*' : ' ';

            printf("| %c ", c);
        }
        printf("|");
    }
    printf("\n -------------------------------\n");
}

// helper functions

static inline byte transform90Degrees(Square square)
{

    Square transformedX = (Square)(7 - square / 8);
    Square transformedY = (Square)(square % 8);

    return (byte)(transformedY * 8 + transformedX);
}

static inline transformed45 *transform45LDegrees(Square square)
{

    int x = square % 8, y = square / 8;
    int translatedX = 7 - x;

    int diagonalLength = (translatedX - y >= 0) ? (x + y) : (14 - (x + y));
    int totalBlocksBefore = (diagonalLength * (diagonalLength + 1)) / 2;

    byte transformedIndex = (translatedX - y >= 0) ? (totalBlocksBefore + x) : (63 - (totalBlocksBefore + translatedX));

    transformed45 *transformedRef = (transformed45 *)malloc(sizeof(transformed45));
    transformedRef->transformedIndex = transformedIndex;
    transformedRef->lengthOfDiagonal = diagonalLength + 1;
    transformedRef->skip = (translatedX - y >= 0) ? totalBlocksBefore : 63 - totalBlocksBefore - diagonalLength;
    // transformedRef -> skip = totalBlocksBefore;

    return transformedRef;
}

static inline transformed45 *transform45RDegrees(Square square)
{

    int x = square % 8, y = square / 8;
    int translatedX = 7 - x;

    int diagonalLength = (x - y >= 0) ? (translatedX + y) : (14 - (translatedX + y));
    int totalBlocksBefore = (diagonalLength * (diagonalLength + 1)) / 2;

    byte transformedIndex = (x - y >= 0) ? (totalBlocksBefore + translatedX) : (63 - (totalBlocksBefore + x));

    transformed45 *transformedRef = (transformed45 *)malloc(sizeof(transformed45));
    transformedRef->transformedIndex = transformedIndex;
    transformedRef->lengthOfDiagonal = diagonalLength + 1;
    transformedRef->skip = (x - y >= 0) ? totalBlocksBefore : 63 - totalBlocksBefore - diagonalLength;

    return transformedRef;
}

// Initializationss

static inline void initAttackRank()
{

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {
        // printf("%d this is the square\n", sq);

        // printf("")

        PositionMask p = A1Square << sq;

        // displayBitboard((Bitboard)p);

        int x = sq % 8, y = sq / 8;
        Statemask start = 1 << x;

        for (Statemask state = 1; state < 256; state++)
        {

            // printf("\n\n\n**** start **** \n\n\n");

            // printf("(x: %d, y: %d)\n\n", x, y);
            // printf("current Postition\n");

            // displayBitboard(p);

            // printf("current state: \n");
            // displayBitboard(state);
            // displayBitboard((uint64_t)(p >> (y * 8)));
            // printf("%ld\n", (p >> (y * 8)));
            // printf("%d\n", state);

            for (int i = 1; i <= x; i++)
            {

                magicBoards.attackRank[sq][state] |= p >> i;
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i <= 7 - x; i++)
            {

                magicBoards.attackRank[sq][state] |= p << i;
                if ((start << i) & state)
                    break;
            }

            // printf("the calculated bitboard\n\n");
            // displayBitboard(magicBoards.attackRank[sq][state]);
        }
    }
}

static inline void initAttackFile()
{

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {

        PositionMask p = A1Square << sq;

        int x = sq % 8, y = sq / 8;

        for (Statemask state = 1; state < 256; state++)
        {

            // printf("\n\n\n**** start **** \n\n\n");

            // printf("(x: %d, y: %d)\n\n", x, y);
            // printf("current Postition\n");

            // displayBitboard(p);

            // printf("current state: \n");
            // displayBitboard(state);

            Statemask start = 1 << y;

            for (int i = 1; i <= y; i++)
            {

                magicBoards.attackRank[sq][state] |= p >> (i * 8);
                if ((start >> i) & state)
                    break;
            }

            for (int i = 1; i <= 7 - y; i++)
            {

                magicBoards.attackRank[sq][state] |= p << (i * 8);
                if ((start << i) & state)
                    break;
            }
            // printf("the calculated bitboard\n\n");
            // displayBitboard(magicBoards.attackRank[sq][state]);
        }
    }
}

static inline void initAttackRightDiagonal()
{

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {

        transformed45 tr45 = magicBoards.rightwardLeaning[sq];

        PositionMask pos = A1Square << sq;

        int limit = 1 << (tr45.lengthOfDiagonal);

        printf("limit: idid chppuuuu\n\n iiiiididiiii %d\n", limit);
        printf("transformIndex: %d, diagonalLenght: %d, skip: %d\n", tr45.transformedIndex, tr45.lengthOfDiagonal, tr45.skip);
        printf("limit: idid chppuuuu\n\n iiiiididiiii %d\n", limit);

        Statemask start = 1 << (tr45.transformedIndex - tr45.skip);

        for (Statemask state = 1; state < limit; state++)
        {

            printf("limit: %d\n, state: %d\n", limit, state);

            printf("\n\n\n**** start **** \n\n\n");

            printf("(x: %d, y: %d)\n\n", sq % 8, sq / 8);
            printf("current Postition\n");

            displayBitboard(pos);

            printf("current state: \n");
            displayBitboard(state);

            for (int i = 1; i <= (tr45.transformedIndex - tr45.skip); i++)
            {

                // printf("i-limit: %d\n, i-value: %d\n", tr45.transformedIndex - tr45.skip, i);

                magicBoards.attackRightDiagonal[sq][state] |= pos << (i * 9);
                if ((start >> i) & state)
                    break;
            }
            // printf("i-limit: %d\n", tr45.lengthOfDiagonal - tr45.transformedIndex);

            for (int i = 1; i < ((tr45.skip + tr45.lengthOfDiagonal) - tr45.transformedIndex); i++)
            {

                magicBoards.attackRightDiagonal[sq][state] |= pos >> (i * 9);
                if ((start << i) & state)
                    break;
            }

            printf("the calculated bitboard\n\n");
            displayBitboard(magicBoards.attackRightDiagonal[sq][state]);
        }
    }
}

static inline void initAttackLeftDiagonal()
{

    for (Square sq = A1; sq <= H8; sq = (Square)(sq + 1))
    {

        transformed45 tr45 = magicBoards.leftwardLeaning[sq];

        PositionMask pos = A1Square << sq;

        int limit = 1 << tr45.lengthOfDiagonal;

        Statemask start = 1 << (tr45.transformedIndex - tr45.skip);
        printf("limit: idid chppuuuu\n\n iiiiididiiii %d\n", limit);
        printf("transformIndex: %d, diagonalLenght: %d, skip: %d\n", tr45.transformedIndex, tr45.lengthOfDiagonal, tr45.skip);
        printf("limit: idid chppuuuu\n\n iiiiididiiii %d\n", limit);

        for (Statemask state = 1; state < limit; state++)
        {
            printf("limit: %d\n, state: %d\n", limit, state);

            printf("\n\n\n**** start **** \n\n\n");

            printf("(x: %d, y: %d)\n\n", sq % 8, sq / 8);
            printf("current Postition\n");

            displayBitboard(pos);

            printf("current state: \n");
            displayBitboard(state);

            for (int i = 1; i <= (tr45.transformedIndex - tr45.skip); i++)
            {

                magicBoards.attackLeftDiagonal[sq][state] |= pos << (i * 7);
                if ((start >> i) & state)
                    break;
            }
            for (int i = 1; i < ((tr45.skip + tr45.lengthOfDiagonal) - tr45.transformedIndex); i++)
            {

                magicBoards.attackLeftDiagonal[sq][state] |= pos >> (i * 7);
                if ((start << i) & state)
                    break;
            }
            printf("the calculated bitboard\n\n");
            displayBitboard(magicBoards.attackLeftDiagonal[sq][state]);
        }
    }
}

static inline void initTransformedIndices()
{

    for (Square s = A1; s <= H8; s = (Square)(s + 1))
    {

        magicBoards.rotated90L[s] = transform90Degrees(s);

        transformed45 *ref = transform45LDegrees(s);

        magicBoards.leftwardLeaning[s].transformedIndex = ref->transformedIndex;
        magicBoards.leftwardLeaning[s].lengthOfDiagonal = ref->lengthOfDiagonal;
        magicBoards.leftwardLeaning[s].skip = ref->skip;

        free(ref);

        ref = transform45RDegrees(s);

        magicBoards.rightwardLeaning[s].transformedIndex = ref->transformedIndex;
        magicBoards.rightwardLeaning[s].lengthOfDiagonal = ref->lengthOfDiagonal;
        magicBoards.rightwardLeaning[s].skip = ref->skip;

        free(ref);
    }
}

static inline void initRanksAndFiles()
{

    for (int i = 0; i < 8; i++)
    {
        magicBoards.ranks[i] = 255UL << i * 8;
        magicBoards.files[i] = 72340172838076673UL << i * 8;
    }
}

static inline void initMagicBoards()
{
    // initTransformedIndices();
    // initAttackRank();
    // initAttackFile();
    // initAttackLeftDiagonal();
    // initAttackRightDiagonal();
    initRanksAndFiles();
}

// #define RANK8 18374686479671623680UL
// #define RANK1 255
// #define FILEA 72340172838076673UL
// #define FILEH 9259542123273814144UL
#define FILEMASK 65793UL
#define UPMASK 7UL
#define DOWNMASK 16140901064495857664UL

static inline Bitboard generateKingMoves(Square square)
{
    int x = square % 8, y = square / 8;

    Bitboard movesGenerated = 0;

    if (x > 0)
    {
        // left
        movesGenerated |= (y) ? FILEMASK << (square - 9) : FILEMASK >> (9 - x);
    }

    if (x < 7)
    {
        // right
        movesGenerated |= (y) ? FILEMASK << (square - 7) : FILEMASK >> (7 - x);
    }

    if (y > 0)
    {
        // down
        movesGenerated |= (DOWNMASK >> (70 - square)) & magicBoards.ranks[y - 1];
    }

    if (y < 7)
    {
        // up
        movesGenerated |= (UPMASK << (square + 7)) & magicBoards.ranks[y + 1];
    }

    return movesGenerated;
}

#define DEKNIGHT_MASK 11529215046068469760UL
#define DKNIGHT_MASK 9799832789158199296UL
#define UKNIGHT_MASK 17UL
#define UEKNIGHT_MASK 5UL

static inline Bitboard generateKnightMoves(Square square)
{
    int x = square % 8, y = square / 8;

    Bitboard movesGenerated = 0;

    if (y > 0)
    {
        // Downwards knight move
        movesGenerated |= (DKNIGHT_MASK >> (69 - square)) & magicBoards.ranks[y - 1];
    }

    if (y > 1)
    {
        // Downward Extreme knight move
        movesGenerated |= (DEKNIGHT_MASK >> (78 - square)) & magicBoards.ranks[y - 2];
    }

    if (y < 7)
    {
        // Upwards knight move
        movesGenerated |= (UKNIGHT_MASK << (square + 6)) & magicBoards.ranks[y + 1];
    }

    if (y < 6)
    {
        // Upwards Extreme knight move
        movesGenerated |= (UEKNIGHT_MASK << (square + 15)) & magicBoards.ranks[y + 2];
    }

    return movesGenerated;
}

int main()
{
    initMagicBoards();
    // printf("hii");

    // displayBitboard(RANK8);
    // displayBitboard(RANK1);
    // displayBitboard(FILEA);
    // displayBitboard(FILEH);
    // displayBitboard(65793 << -8);
    // displayBitboard(6052837899185946708UL);

    // for(Square i = A1; i <= H8; i++)
    // {
        //     printf("Sqaure: %c%c\n", 'A' + (i % 8), '1' + (i / 8));
        //     displayBitboard(generateKnightMoves(i));
        // }

        // for(int i = 0; i < 8; i++)
        // {
            // displayBitboard(magicBoards.ranks[i]);}

            // for(int i = 0; i < 64; i++)
            // {

                //     for(int j = 1; j < 256; j++)
                // {

                    //         printf("state: %d, position: %d \n", j, i);

                    //         printf("this is the state\n");
                    //         displayBitboard(j);

                    //         printf("this the actual bitboard\n");
                    //         displayBitboard(magicBoards.attackRank[i][j]);

                    //     }
                    // }

    return 0;
}