#include "./includes/boards.h"
#include "./includes/utils.h"
#include "./includes/bitboards.h"
#include "./includes/magicBoards.h"

#include <stdbool.h>
#include <stdlib.h>

void initBoards(Boards *boards, char *fenString)
{
    PlainBoard plainBoard = boards->board;

    Bitboards bitboards = boards->bitboards;

    initMagicBoards();

    initPlainBoard(plainBoard);

    initBitboards(&(boards->bitboards));

    if (fenString == NULL)
        fenString = DEFAULT_FEN;

    Square index = H1;

    while (*fenString != ' ')
    {
        if (*fenString == '/')
        {
            index -= 15;
        }
        else if (*fenString >= '1' && *fenString <= '8')
        {
            index += *fenString - '0';
        }
        else
        {
            putPieceOnSquare((Piece)*fenString, index, plainBoard);
            setPieceOnBitboards(&(boards->bitboards), index, (Piece)*fenString);

            index++;
        }

        fenString++;
    }
}

void playMoveOnBoards(Boards *boards, Move *move)
{
    Piece movingPiece = (Piece)boards->board[move->from];

    putPieceOnSquare(boards->board, movingPiece, move->to);
    removePieceOnSquare(boards->board, move->from);

    playMoveOnBitboards(&(boards->bitboards), move, movingPiece);
}

void undoMoveOnBoards(Boards *boards, Move *move)
{
}

void generateLegalMoves(Boards *boards, Square from)
{



}


void generatePseudoLegalMoves(Boards *boards, Square from) 
{
    Piece selectedPiece = boards -> board[from];

    switch (selectedPiece)
    {
    case WHITE_QUEEN:
    case BLACK_QUEEN:
        return 
            generateBishopMoves(boards, from) |
            generateRookMoves(boards, from);
    case WHITE_PAWN:
    case BLACK_PAWN:
        return;
    case WHITE_ROOK:
    case BLACK_ROOK:
        return generateRookMoves(boards, from);
    case WHITE_BISHOP:
    case BLACK_BISHOP:
        return generateBishopMoves(boards, from);
    case WHITE_KNIGHT:
    case BLACK_KNIGHT:
        return __knightAttack__[from];
    case WHITE_KING:
    case BLACK_KING:
        return __kingAttack__[from];
    
    default:
        return 0;
    }

}

// Inline functions

inline static void putPieceOnSquare(PlainBoard board, Piece piece, Square square)
{
    board[square] = piece;
}

inline static void removePieceOnSquare(PlainBoard board, Square square)
{
    board[square] = NULL_PIECE;
}

inline static void initPlainBoard(PlainBoard pb)
{
    for (Square s = A1; s <= H8; s++)
    {
        pb[s] = NULL_PIECE;
    }
}