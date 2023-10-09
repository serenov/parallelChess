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
    putPieceOnSquare(boards->board, (Piece)boards->board[move->from], move->to);
    removePieceOnSquare(boards->board, move->from);

    playMoveOnBitboards(&(boards->bitboards), move);
}

void undoMoveOnBoards(Boards *boards, Move *move)
{
}

// Inline functions

inline static void putPieceOnSquare(PlainBoard board, Piece piece, Square square)
{
    board[square] = piece;
}

inline static void removePieceOnSquare(PlainBoard board, Square square)
{
    board[square] = nullPiece;
}

inline static void initPlainBoard(PlainBoard pb)
{
    for (Square s = A1; s <= H8; s++)
    {
        pb[s] = nullPiece;
    }
}