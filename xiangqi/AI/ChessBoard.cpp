#include "ChessBoard.h"


ChessBoard::ChessBoard()
{
}


ChessBoard::~ChessBoard()
{
}

void ChessBoard::initBoard()
{
    for (int i = 0; i < BOARD_ROW_MAX + 2; ++i) 
    {
        for (int j = 0; j < BOARD_COL_MAX + 2; ++j)
        {
            if (i == 0 || j == 0 || i == BOARD_ROW_MAX+1 || j == BOARD_COL_MAX+1)
            {
                board[i][j] = Chess{-1,-1};
            }
            board[i][j] = Chess{ 0,0 };
        }
    }
    board[1][1] = board[1][9] = Chess{ CHESSTYPE_CHARIOT,CHESS_COLOR_BLACK };
    board[10][1] = board[10][9] = Chess{ CHESSTYPE_CHARIOT,CHESS_COLOR_RED };
    board[1][2] = board[1][8] = Chess{ CHESSTYPE_HORSE,CHESS_COLOR_BLACK };
    board[10][2] = board[10][8] = Chess{ CHESSTYPE_HORSE,CHESS_COLOR_RED };
    board[1][3] = board[1][7] = Chess{ CHESSTYPE_ELEPHANT,CHESS_COLOR_BLACK };
    board[10][3] = board[10][7] = Chess{ CHESSTYPE_ELEPHANT,CHESS_COLOR_RED };
    board[1][4] = board[1][6] = Chess{ CHESSTYPE_ADVISER,CHESS_COLOR_BLACK };
    board[10][4] = board[10][6] = Chess{ CHESSTYPE_ADVISER,CHESS_COLOR_RED };
    board[1][5]  = Chess{ CHESSTYPE_KING,CHESS_COLOR_BLACK };
    board[10][5]  = Chess{ CHESSTYPE_KING,CHESS_COLOR_RED };
    board[3][2] = board[3][8] = Chess{ CHESSTYPE_CANNON,CHESS_COLOR_BLACK };
    board[8][2] = board[8][8] = Chess{ CHESSTYPE_CANNON,CHESS_COLOR_RED };
    board[4][1] = board[4][3] = board[4][5] = board[4][7] = board[4][9] = Chess{ CHESSTYPE_SOLDIER,CHESS_COLOR_BLACK };
    board[7][1] = board[7][3] = board[7][5] = board[7][7] = board[7][9] = Chess{ CHESSTYPE_SOLDIER,CHESS_COLOR_RED };
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

bool ChessBoard::checkMove(Position from, Position to)
{
    if (to.row > BOARD_ROW_MAX || to.row < 1 || to.col > BOARD_COL_MAX || to.col < 1)//³ö½ç
    {
        return false;
    }

    switch (board[from.row][from.col].type)
    {
    case CHESSTYPE_KING:
        if (board[from.row][from.col].color == CHESS_COLOR_RED)
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
    board[to.row][to.col] = board[from.row][from.col];
    board[from.row][from.col] = { 0,0 };  
    return true;
}


