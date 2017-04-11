#ifndef __AI_DEFINES_H__
#define __AI_DEFINES_H__
#include <cstdint>
using namespace std;

enum CHESSTYPE
{
    CHESSTYPE_EMPTY,
    CHESSTYPE_KING,
    CHESSTYPE_ADVISER,
    CHESSTYPE_ELEPHANT,
    CHESSTYPE_HORSE,
    CHESSTYPE_CHARIOT,
    CHESSTYPE_CANNON,
    CHESSTYPE_SOLDIER,
    CHESSTYPE_COUNT
};

#define BOARD_ROW_MAX 10
#define BOARD_COL_MAX 9

#define CHESS_COLOR_BLACK 1
#define CHESS_COLOR_RED   0




struct Position
{
    uint8_t row,col;
};

Position operator-(const Position &a,const Position &b)
{
    return Position{ a.row - b.row,a.col - b.col };
}

bool operator==(const Position &a, const Position &b)
{
    return a.row == b.row && a.col == b.col;
}

#endif // !__AI_DEFINES_H__

