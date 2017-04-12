#ifndef __AI_DEFINES_H__
#define __AI_DEFINES_H__
#include <cstdint>
#include <bitset>
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

#define CHESS_COLOR_BLACK -1
#define CHESS_COLOR_RED   1

enum DIRECTION4
{
    DIRECTION4_UP,
    DIRECTION4_DOWN,
    DIRECTION4_LEFT,
    DIRECTION4_RIGHT,
    DIRECTION4_COUNT
};


struct Position
{
    int8_t row,col;
    size_t to_index() const
    {
        return row * BOARD_COL_MAX + col;
    }
    void add(int8_t r, int8_t c)
    {
        row += r;
        col += c;
    }
    bool addAndCheck(Position a)
    {
        row += a.row;
        col += a.col;
        if (row > -1 && row < BOARD_ROW_MAX && col > -1 && col < BOARD_COL_MAX)
        {
            return true;
        }
        return false;
    }
    void set(Position a, int8_t r, int8_t c)
    {
        row = a.row + r;
        col = a.col + c;
    }
    bool checkRange() const
    {
        if (row > -1 && row < BOARD_ROW_MAX && col > -1 && col < BOARD_COL_MAX)
        {
            return true;
        }
        return false;
    }
};

Position operator+(const Position &a,const Position &b)
{
    return Position{ a.row + b.row,a.col + b.col };
}

bool operator==(const Position &a, const Position &b)
{
    return a.row == b.row && a.col == b.col;
}



struct ChessStep
{
    Position from;
    Position to;
};


#endif // !__AI_DEFINES_H__