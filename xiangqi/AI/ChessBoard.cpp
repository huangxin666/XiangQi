#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
}


ChessBoard::~ChessBoard()
{
}

void ChessBoard::initBoard()
{
    for (int i = 0; i < BOARD_ROW_MAX; ++i)
    {
        for (int j = 0; j < BOARD_COL_MAX; ++j)
        {
            if (chessInitPos[i][j])
            {
                board[i][j].type = chessInitPos[i][j];
                board[i][j].info = new ChessInfo;
                board[i][j].state = j > 5 ? CHESS_COLOR_RED : CHESS_COLOR_BLACK;
            }
        }
    }
}

void ChessBoard::initGlobalChessInfo()
{
    for (int i = 0; i < BOARD_ROW_MAX; ++i)
    {
        for (int j = 0; j < BOARD_COL_MAX; ++j)
        {
            if (board[i][j].type)
            {
                updateMoveMap(Position{ i,j }, board[i][j].info->moveMap);
                board[i][j].info->flex = getFlexibility(Position{ i,j });
            }
        }
    }
}

int ChessBoard::updateMoveMap(Position pos, bitset<90> &map)
{
    map.reset();
    int state = board[pos.row][pos.col].state;
    if (state == 0 || board[pos.row][pos.col].type == CHESSTYPE_EMPTY)
    {
        return 0;
    }
    Position temp;
    switch (board[pos.row][pos.col].type)
    {
    case CHESSTYPE_KING:
        for (int i = 0; i < 4; ++i)
        {
            temp = pos + direction_king_chariot_connon[i];
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
        }
        break;
    case CHESSTYPE_ADVISER://士
        for (int i = 0; i < 4; ++i)
        {
            temp = pos + direction_adviser[i];
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
        }
        break;
    case CHESSTYPE_ELEPHANT:
        for (int i = 0; i < 4; ++i)
        {
            temp = pos + direction_elephant[i];
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
        }
        break;
    case CHESSTYPE_CHARIOT://车
        for (int i = 0; i < 4; ++i)
        {
            temp = pos;
            while (temp.addAndCheck(direction_king_chariot_connon[i]))
            {
                if (board[temp.row][temp.col].state == 0)
                {
                    map[temp.to_index()] = 1;
                }
                else if (board[temp.row][temp.col].state == -state)
                {
                    map[temp.to_index()] = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        break;
    case CHESSTYPE_HORSE:
        for (int i = 0; i < 8; ++i)
        {
            temp = pos + direction_horse[i];
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
        }
        break;
    case CHESSTYPE_CANNON:
        for (int i = 0; i < 4; ++i)
        {
            temp = pos;
            while (temp.addAndCheck(direction_king_chariot_connon[i]))
            {
                if (board[temp.row][temp.col].state == 0)
                {
                    map[temp.to_index()] = 1;
                }
                else
                {
                    while (temp.addAndCheck(direction_king_chariot_connon[i]))
                    {
                        if (board[temp.row][temp.col].state == state)
                        {
                            break;
                        }
                        else if (board[temp.row][temp.col].state == -state)
                        {
                            map[temp.to_index()] = 1;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        break;
    case CHESSTYPE_SOLDIER:
        if (state == CHESS_COLOR_RED)
        {
            temp = pos + Position{ 0, -1 };
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
            if (pos.col < 5)//过河兵
            {
                temp = pos + Position{ 1, 0 };
                if (temp.checkRange() && board[temp.row][temp.col].state != state)
                {
                    map[temp.to_index()] = 1;
                }
                temp = pos + Position{ -1, 0 };
                if (temp.checkRange() && board[temp.row][temp.col].state != state)
                {
                    map[temp.to_index()] = 1;
                }
            }
        }
        else if (state == CHESS_COLOR_BLACK)
        {
            temp = pos + Position{ 0, 1 };
            if (temp.checkRange() && board[temp.row][temp.col].state != state)
            {
                map[temp.to_index()] = 1;
            }
            if (pos.col > 4)//过河兵
            {
                temp = pos + Position{ 1, 0 };
                if (temp.checkRange() && board[temp.row][temp.col].state != state)
                {
                    map[temp.to_index()] = 1;
                }
                temp = pos + Position{ -1, 0 };
                if (temp.checkRange() && board[temp.row][temp.col].state != state)
                {
                    map[temp.to_index()] = 1;
                }
            }
        }
        break;
    default:
        break;
    }
    return 0;
}

uint8_t ChessBoard::getFlexibility(Position pos)
{
    if (board[pos.row][pos.col].info == NULL)
    {
        return 0;
    }
    return board[pos.row][pos.col].info->moveMap.count() * 100 / chessFlexBase[board[pos.row][pos.col].type];
}

bool ChessBoard::moveChess(Position from, Position to)
{
    if (board[from.row][from.col].info == NULL)
    {
        return false;
    }
    //if (!to.checkRange())//出界
    //{
    //    return false;
    //}
    if (board[from.row][from.col].info->moveMap[to.to_index()] == 0)
    {
        return false;
    }
    board[to.row][to.col].info = board[from.row][from.col].info;
    board[to.row][to.col].type = board[from.row][from.col].type;
    board[to.row][to.col].state = board[from.row][from.col].state;

    board[from.row][from.col].type = 0;
    board[from.row][from.col].info = NULL;
    board[from.row][from.col].state = 0;
    return true;
}


uint8_t ChessBoard::chessFlexBase[CHESSTYPE_COUNT] = {
    0,
    4,
    4,
    4,
    8,
    17,
    17,
    3
};

uint8_t ChessBoard::chessInitPos[BOARD_ROW_MAX][BOARD_COL_MAX] =
{
    5,4,3,2,1,2,3,4,5,
    0,0,0,0,0,0,0,0,0,
    0,6,0,0,0,0,0,6,0,
    7,0,7,0,7,0,7,0,7,
    0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,
    7,0,7,0,7,0,7,0,7,
    0,6,0,0,0,0,0,6,0,
    0,0,0,0,0,0,0,0,0,
    5,4,3,2,1,2,3,4,5,
};

Position ChessBoard::direction_king_chariot_connon[4] =
{
    { 0,1 },
    { 0,-1 },
    { -1,0 },
    { 1,0 }
};

Position ChessBoard::direction_adviser[4] =
{
    { 1,1 },
    { -1,-1 },
    { -1,1 },
    { 1,-1 }
};

Position ChessBoard::direction_elephant[4] =
{
    { 2,2 },
    { -2,-2 },
    { -2,2 },
    { 2,-2 }
};
Position ChessBoard::direction_horse[8] = 
{
    { 2,1 },
    { -2,-1 },
    { -2,1 },
    { 2,-1 },
    { 1,2 },
    { -1,-2 },
    { -1,2 },
    { 1,-2 }
};