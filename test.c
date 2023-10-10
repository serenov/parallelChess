// #include <stdio.h>
// #include <stdint.h>

// #include <stdlib.h>


// typedef uint64_t Bitboard;


// typedef char byte;

// typedef byte transformed90Indices[64];

// typedef struct {

//     // To save space...

//     byte transformedIndex;
//     byte lengthOfDiagonal;
//     byte skip;

// } transformed45;


// typedef transformed45 transformed45Indices[64];

// typedef enum {

//     A1, B1, C1, D1, E1, F1, G1, H1,
//     A2, B2, C2, D2, E2, F2, G2, H2,
//     A3, B3, C3, D3, E3, F3, G3, H3,
//     A4, B4, C4, D4, E4, F4, G4, H4,
//     A5, B5, C5, D5, E5, F5, G5, H5,
//     A6, B6, C6, D6, E6, F6, G6, H6,
//     A7, B7, C7, D7, E7, F7, G7, H7,
//     A8, B8, C8, D8, E8, F8, G8, H8,
//     null

// } Square;


// static struct MagicBoards{

//     Bitboard attackRank[64][256];
//     Bitboard attackFile[64][256];

//     Bitboard attackRightDiagonal[64][256];
//     Bitboard attackLeftDiagonal[64][256];


//     // Extra information about the rotated boards

//     transformed45Indices leftwardLeaning;
//     transformed45Indices rightwardLeaning;
//     transformed90Indices rotated90L;

// } magicBoards;



// static inline byte transform90Degrees(Square square) {

//     Square transformedX = (Square) (7 - square / 8);
//     Square transformedY = (Square) (square % 8); 

//     // printf("Transformed90Degrees Square: %d\n\n", (transformedY * 8 + transformedX));  

//     return (byte) (transformedY * 8 + transformedX);

// }

// static inline transformed45* transform45LDegrees(Square square) {

//     int x = square % 8;
//     int y = square / 8;
//     int translatedX = 7 - x;

//     int diagonalLength = (translatedX - y >= 0) ? (x + y) : (14 - (x + y));
//     int totalBlocksBefore = (diagonalLength * (diagonalLength + 1)) / 2;

//     byte transformedIndex = (translatedX - y >= 0) ? (totalBlocksBefore + x) : (63 - (totalBlocksBefore + translatedX));

//     transformed45* transformedRef = (transformed45*)malloc(sizeof(transformed45));
//     transformedRef -> transformedIndex = transformedIndex;
//     transformedRef -> lengthOfDiagonal = diagonalLength + 1;
//     transformedRef -> skip = (translatedX - y >= 0) ? totalBlocksBefore: 63 - totalBlocksBefore - diagonalLength;

//     // printf("(x: %d, y: %d)\n", x, y);
//     // printf("Square: %c%c\n", 'A' + x, '1' + y);
//     // printf("diagonalLengthPrev: %d, diagonalLenghtCurr: %d\n", diagonalLength, diagonalLength + 1);
//     // printf("%d totalBlocks\n", totalBlocksBefore);
//     // printf("Transformed Square: %d\n\n", transformedIndex);  


//     return transformedRef;
// }

// static inline transformed45* transform45RDegrees(Square square) {

//     int x = square % 8;
//     int y = square / 8;
//     int translatedX = 7 - x;

//     int diagonalLength = (x - y >= 0) ? (translatedX + y) : (14 - (translatedX + y));
//     int totalBlocksBefore = (diagonalLength * (diagonalLength + 1)) / 2;

//     byte transformedIndex = (x - y >= 0) ? (totalBlocksBefore + translatedX) : (63 - (totalBlocksBefore + x));

//     transformed45* transformedRef = (transformed45*)malloc(sizeof(transformed45));
//     transformedRef -> transformedIndex = transformedIndex;
//     transformedRef -> lengthOfDiagonal = diagonalLength + 1;
//     transformedRef -> skip = (x - y >= 0) ? totalBlocksBefore: 63 - totalBlocksBefore - diagonalLength;
    


//     // printf("(x: %d, y: %d)\n", x, y);
//     // printf("Square: %c%c\n", 'A' + x, '1' + y);
//     // printf("diagonalLengthPrev: %d, diagonalLenghtCurr: %d\n", diagonalLength, diagonalLength + 1);
//     // printf("Transformed Square: %d\n\n", transformedIndex);  



//     return transformedRef;
// }

// static inline void initTransformedIndices(){

//     for(Square s = A1; s <= H8; s = (Square) (s + 1)){

//         // printf("\nFor the Square: %d,\n", s);

//         magicBoards.rotated90L[s] = transform90Degrees(s);



//         transformed45* ref = transform45LDegrees(s);

//         magicBoards.leftwardLeaning[s].transformedIndex = ref -> transformedIndex;
//         magicBoards.leftwardLeaning[s].lengthOfDiagonal = ref -> lengthOfDiagonal;
//         magicBoards.leftwardLeaning[s].skip = ref -> skip;

//         free(ref);


//         ref = transform45RDegrees(s);

//         magicBoards.rightwardLeaning[s].transformedIndex = ref -> transformedIndex;
//         magicBoards.rightwardLeaning[s].lengthOfDiagonal = ref -> lengthOfDiagonal;
//         magicBoards.rightwardLeaning[s].skip = ref -> skip;

//         free(ref);

//         // printf("\n end.... \n\n");
//     }

// }





// void display45(transformed90Indices t90){
//     //this is the new cool...

//     for(int y = 0; y < 8; y++) {
//     // for(int y = 7; y > -1; y--) {

//         // printf("\n --------------------------------------- \n");
//         for(int x = 0; x < 8; x++){
//             byte Index = t90[y * 8 + x];
//             // byte Index = t45[y * 8 + x].lengthOfDiagonal;
//             // byte Index = t45[y * 8 + x].skip;
//             // printf("%c%c, ", 'A' + Index % 8, '1' + Index / 8);
//             printf("%02d, ", y * 8);
//         }
//         // printf("|");
//         printf("\n");

//     }
//     // printf("\n --------------------------------------- \n");
// }


// // void display90(transformed90Indices t90){

// //     for(int y = 0; y < 8; y++) {

// //         printf("\n --------------------------------------- \n");
// //         for(int x = 0; x < 8; x++){
// //             byte Index = t90[y * 8 + x];
// //             printf("| %02d ", Index);
// //         }
// //         printf("|");

// //     }
// //     printf("\n --------------------------------------- \n");
// // }

// int main() {
//     // Write C code here
//     initTransformedIndices();
//     // display45(magicBoards.);
//     // display45(magicBoards.leftwardLeaning);
//     display45(magicBoards.rotated90L);
    
//     return 0;
// }


