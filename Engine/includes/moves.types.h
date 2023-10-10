#pragma once

#include "./squares.types.h"

typedef enum 
{
    BLAND,
    PAWN_MOVE,
    CAPTURE,
    ENPASSANT_W,
    ENPASSANT_B,
    CASTLE_W_LEFT,
    CASTLE_W_RIGHT,
    CASTLE_B_LEFT,
    CASTLE_B_RIGHT,
    PROMOTION_W_P,
    PROMOTION_W_N,
    PROMOTION_W_B,
    PROMOTION_W_R,
    PROMOTION_W_Q,
    PROMOTION_B_P,
    PROMOTION_B_N,
    PROMOTION_B_B,
    PROMOTION_B_R,
    PROMOTION_B_Q
} Movetype;

typedef struct 
{

    Square from;
    Square to;

} Move;



