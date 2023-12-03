#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 19;
    boardSizeY = 9;

    foodPos.setObjPos(-1, -1, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
   
    exitFlag = true;
    
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score++; 
}

void GameMechs::generateFood(objPos blockOff)
{
    

    int randX, randY;
    char symbol = 'o';

    do
    {
        randX = 1 + (rand() % (boardSizeX - 1));
        randY = 1 + (rand() % (boardSizeY - 1));
    }while((randX == blockOff.x) && (randY == blockOff.y));
    foodPos.setObjPos(randX, randY, symbol);


}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}


