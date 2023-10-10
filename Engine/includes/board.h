#include "./pieces.h"
#include "./squares.h"

typedef Piece PlainBoard[64];

inline static void putPieceOnSquare(PlainBoard board, Piece piece, Square square);
inline static void removePieceOnSquare(PlainBoard board, Square square);

