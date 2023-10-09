#include "includes/moves.h"
#include "includes/boards.h"
#include "includes/bitboards.h"
#include "includes/squares.h"
#include "includes/pieces.h"
#include "includes/magicBoards.h"

#include <stdbool.h>
#include <stdlib.h>

static inline Bitboard getPseudoLegalMoves(Boards *boards, Square square)
{

    switch ((boards->board[square]) | 32)
    {

    case 'K':
        return __kingAttack__[square];

    case 'Q':
        return __attackRank__[square][getRankState(boards, square)] |
               __attackFile__[square][getFileState(boards, square)] |
               __attackLeftDiagonal__[square][getLDiagonal(boards, square)] |
               __attackRightDiagonal__[square][getRDiagonal(boards, square)];

    case 'R':
        return __attackRank__[square][getRankState(boards, square)] |
               __attackFile__[square][getFileState(boards, square)];

    case 'B':
        return __attackLeftDiagonal__[square][getLDiagonal(boards, square)] |
               __attackRightDiagonal__[square][getRDiagonal(boards, square)];

    case 'N':
        return __knightAttack__[square];
        boards->state.colorToPlay;

    case 'P':
        return __pawnAttack__[!(boards->state.colorToPlay)][square];

    default:
        return 0;
    }
}

static inline Bitboard allAttackedSquares(Boards *boards)
{

    Bitboard attackedSquares = 0;

    Bitboard occupiedBoard = (boards->state.colorToPlay == white) ? boards->bitboards.blackPieces : boards->bitboards.whitePieces;

    while (occupiedBoard)
    {
        Square sq = popFirstBit(&occupiedBoard);
        attackedSquares |= getPseudoLegalMoves(boards, sq);
    }

    return attackedSquares;
}

static inline Bitboard castleRightMove(Boards *boards, Color color, Bitboard unsafeSquares)
{

    if (boards->state.canCastleRight[color])
        return (color == white) ? 3UL << 5 : 3UL << 61;

    return 0;
}

static inline Bitboard castleLeftMove(Boards *boards, Color color, Bitboard unsafeSquares)
{

    if (boards->state.canCastleLeft[color])
        return (color == white) ? 3UL << 3 : 3UL << 59;

    return 0;
}

Bitboard generateLegalMoves(Boards *boards, Square square)
{

    const Piece piece = boards->board[square];

    const Color colorToPlay = boards->state.colorToPlay;

    Bitboard movesGenerated = 0;

    switch (piece | 32)

    {
    case 'K':

        Bitboard unsafeSquares = attackedSquares(boards);

        break;

    default:
        break;
    }

    // switch (piece | 32)
    //
    // {
        // case /* constant-expression */:
        //     /* code */
        //     break;

        // default:
        //     break;
        // }

    // }

    // bool isLegal(Boards* boards, Square from, Square to)
    // {

        //     Piece selectedPiece = boards -> board[from];

        //     Color selectedColor = getColorByPiece(selectedPiece);

        //     BoardState* boardState = &(boards -> state);

        //     Bitboard legalMoves = getMoves(boards, selectedPiece, from);

        //     if(
        //         selectedColor == noColor ||
        //         selectedColor != boardState -> colorToPlay ||
        //         ~legalMoves & (A1Square << to)
        //     ) return false;

        //     return true;
        // }

        // static inline Bitboard isEnpassant(Piece p, PositionMask fromMask, PositionMask toMask)
        // {
            //     Bitboard enpassantMask = fromMask << 9 | fromMask << 7 | fromMask >> 9 | fromMask >> 7;
            //     return ((p == 'p' || p == 'P') && (enpassantMask & toMask));
            // }

            // Move* moveConstructor(Boards* boards, Square from, Square to)
            // {

                //     PositionMask fromMask = A1Square << from;
                //     PositionMask toMask = A1Square << to;

                //     Move* move = (Move *) malloc(sizeof(Move));

                //     move -> from = from;
                //     move -> to = to;
                //     move -> extraInformation = 0;

                //     if(magicBoards.castlingMask & (fromMask | toMask))
                // {
                    //         // Castling Move
                    //         move -> type = CASTLING;

                    //         CastleMoveInformation* info = (CastleMoveInformation *) malloc(sizeof(CastleMoveInformation));

                    //         info -> from = ((from % 8) < 4)? to - 2: to + 1;
                    //         info -> to = ((from % 8) < 4)? to + 1: to - 1;

                    //         move -> extraInformation = info;
                    //     }
                    //     else if(boards -> board[to] != nullPiece)
                    // {
                        //         // Capture Move
                        //         capturePieceInformation* info = (capturePieceInformation *) malloc(sizeof(capturePieceInformation));
                        //         info -> capturedPiece = boards -> board[to];
                        //         move -> extraInformation = info;
                        //     }
                        //     else if(isEnpassant(boards -> board[from], fromMask, toMask))
                        // {
                            //         EnpassantInformation* info = (EnpassantInformation *) malloc(sizeof(EnpassantInformation));
                            //         // info -> capturedAt
                            //     }

                            //     return move;

                            // }

                            // bool pushMove(Boards* boards, Move* move)
                            // {

                                // }

                                // bool popMove(Boards* boards)
                                // {

                                    // 
}