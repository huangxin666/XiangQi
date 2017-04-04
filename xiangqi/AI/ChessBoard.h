#ifndef __AI_CHESSBOARD_H__
#define __AI_CHESSBOARD_H__
#include "defines.h"

class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    void initBoard();
    int getAvailableMove(Position pos, Position *result);
    bool checkMove(Position from, Position to);
    bool moveChess(Position from, Position to);
    Chess board[BOARD_ROW_MAX + 2][BOARD_COL_MAX + 2];
};

#endif // !__AI_CHESSBOARD_H__