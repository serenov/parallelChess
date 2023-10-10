#pragma once

#define MAX_NUMBER_OF_MOVES 1000

#include <stdbool.h>
#include <stdlib.h>
#include "./squares.types.h"
#include "./pieces.types.h"
#include "./bitboards.types.h"
#include "./moves.types.h"
#include "./magicBoards.types.h"


typedef Piece PlainBoard[64];

typedef Square* SquaresList;


typedef enum 

{
    RUNNING,
    STALEMATE,
    CHEKCMATE,
    BLACK_RESIGN,
    WHITE_RESIGN,
    DRAW_BY_REP,
    DRAW_BY_50

} GameStatus;

typedef struct 
{
    
    Move move;
    Movetype type;

} MoveInfo;

typedef struct 
{
    bool canCastleRight[2];
    bool canCastleLeft[2];

    Square Enpassant;

    GameStatus status;

    Color colorToPlay;

    MoveInfo movesHistory[MAX_NUMBER_OF_MOVES];

} BoardState;


typedef struct 
{

    PlainBoard board;
    Bitboards bitboards;
    BoardState state;

} Boards;