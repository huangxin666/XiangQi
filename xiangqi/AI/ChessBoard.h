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
    void initGlobalChessInfo();
    int updateMoveMap(Position pos, bitset<90> &map);
    bool moveChess(Position from, Position to);
    uint8_t getFlexibility(Position pos);

public:
    Chess board[BOARD_ROW_MAX][BOARD_COL_MAX];
private:
    static uint8_t chessInitPos[BOARD_ROW_MAX][BOARD_COL_MAX];
    static uint8_t chessInitFlex[CHESSTYPE_COUNT];
    static uint8_t chessFlexBase[CHESSTYPE_COUNT];
    static uint8_t positionWeight[BOARD_ROW_MAX][BOARD_COL_MAX];
    static uint32_t transTableRD32[BOARD_ROW_MAX][BOARD_COL_MAX][CHESSTYPE_COUNT][2];
    static uint64_t transTableRD64[BOARD_ROW_MAX][BOARD_COL_MAX][CHESSTYPE_COUNT][2];

private:
    static Position direction_king_chariot_connon[4];
    static Position direction_adviser[4];
    static Position direction_elephant[4];
    static Position direction_horse[8];
};

#endif // !__AI_CHESSBOARD_H__