#pragma once
#include "ChessBoard.h"
#include <vector>
class Game
{
public:
    Game();
    ~Game();
    void move();
    void undo();
    ChessBoard chessboard;
    std::vector<ChessBoard> boardList;
};

