#ifndef __AI_CHESSBOARD_H__
#define __AI_CHESSBOARD_H__
#include "defines.h"
#include "Chess.h"
class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    void initBoard();
    int getAvailableMove(Position pos, Position *result);
    bool checkMove(Position from, Position to);
    bool moveChess(Position from, Position to);
    uint8_t getFlexibility(Position pos);
    Chess board[BOARD_ROW_MAX][BOARD_COL_MAX];

private:
    static uint8_t chessInitPos[BOARD_ROW_MAX][BOARD_COL_MAX];
    static uint8_t chessInitFlex[CHESSTYPE_COUNT];
    static uint8_t chessFlexBase[CHESSTYPE_COUNT];
    static uint8_t positionWeight[BOARD_ROW_MAX][BOARD_COL_MAX];
};

#endif // !__AI_CHESSBOARD_H__