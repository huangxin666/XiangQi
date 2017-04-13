#pragma once
#include "ChessBoard.h"
#include <vector>

enum GAMESTATE
{
    GAMESTATE_WAIT_PLAYER,
    GAMESTATE_WAIT_PUTCHESS,
    GAMESTATE_WAIT_AI,
    GAMESTATE_WIN,
    GAMESTATE_FAIL
};

class Game
{
public:
    Game();
    ~Game();
    void initGame();
    void move(Position from, Position to);
    void undo();
    void redo();
public:
    ChessBoard* chessboard;
    std::vector<ChessBoard*> stepList;
    size_t currentStep;
    int gameState;
    int playerColor;
};

