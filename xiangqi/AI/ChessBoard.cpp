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
                board[i][j].info->flex = chessInitFlex[board[i][j].type];
                board[i][j].state = j > 5 ? CHESS_COLOR_RED : CHESS_COLOR_BLACK;
            }
        }
    }
}

int ChessBoard::getAvailableMove(Position pos, Position * result)
{
    switch (board[pos.row][pos.col].type)
    {
    case CHESSTYPE_KING:
        break;
    case CHESSTYPE_ADVISER:
        break;
    case CHESSTYPE_ELEPHANT:
        break;
    case CHESSTYPE_CHARIOT:
        break;
    case CHESSTYPE_HORSE:
        break;
    case CHESSTYPE_CANNON:
        break;
    case CHESSTYPE_SOLDIER:
        break;
    default:
        break;
    }
    return 0;
}

uint8_t ChessBoard::getFlexibility(Position pos)
{

}

bool ChessBoard::checkMove(Position from, Position to)
{
    if (to.row > BOARD_ROW_MAX || to.row < 1 || to.col > BOARD_COL_MAX || to.col < 1)//³ö½ç
    {
        return false;
    }

    switch (board[from.row][from.col].type)
    {
    case CHESSTYPE_KING:
        if (board[from.row][from.col].state == CHESS_COLOR_RED)
        {

        }
        break;
    case CHESSTYPE_ADVISER:
        break;
    case CHESSTYPE_ELEPHANT:
        break;
    case CHESSTYPE_CHARIOT:
        break;
    case CHESSTYPE_HORSE:
        break;
    case CHESSTYPE_CANNON:
        break;
    case CHESSTYPE_SOLDIER:
        break;
    default:
        break;
    }
    return false;
}

bool ChessBoard::moveChess(Position from, Position to)
{
    if (!checkMove(from, to))
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

uint8_t chessInitFlex[CHESSTYPE_COUNT] = {
    0,
    25,
    25,
    50,
    25,
    11,
    64,
    33
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