#include "stdafx.h"
#include "Game.h"
#include "defines.h"

Game::Game():playerColor(CHESS_COLOR_RED), currentStep(0), gameState(GAMESTATE_WAIT_PLAYER)
{
    initGame();
}


Game::~Game()
{
}

void Game::initGame()
{
    for (auto chessboard : stepList)
    {
        if (chessboard)
        {
            delete chessboard;
        }
    }
    stepList.clear();

    chessboard = new ChessBoard();
    chessboard->initBoard();
    chessboard->initGlobalChessInfo();
    stepList.push_back(chessboard);
    currentStep = 0;
}

void Game::move(Position from, Position to)
{
    /*if (gameState != GAMESTATE_WAIT_PUTCHESS)
    {
        return;
    }*/
    ChessBoard* temp = new ChessBoard();
    *temp = *chessboard;
    chessboard->clearGlobalChessInfo();
    if (temp->moveChess(from, to))
    {
        while (currentStep + 1 < stepList.size())
        {
            delete stepList.back();
            stepList.pop_back();
        }
        stepList.push_back(temp);
        currentStep++;
    }
}

void Game::undo()
{
    /*if (gameState == GAMESTATE_WAIT_AI || gameState == GAMESTATE_WAIT_PUTCHESS)
    {
        return;
    }*/
    if (stepList.empty())
    {
        return;
    }
    currentStep--;
    chessboard->clearGlobalChessInfo();
    chessboard = stepList[currentStep];
    chessboard->initGlobalChessInfo();
}

void Game::redo()
{
    if (currentStep + 1 == stepList.size())
    {
        return;
    }
    currentStep++;
    chessboard->clearGlobalChessInfo();
    chessboard = stepList[currentStep];
    chessboard->initGlobalChessInfo();
}