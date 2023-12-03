#include "GameMechs.h"
#include "MacUILib.h"

#include <ctime>

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
    score = 0;

    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;

    foodPos.setObjPos(-1, -1, 'o');
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
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

void GameMechs::setLoseTrue()
{
   
    loseFlag = true;
    
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

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    srand(time(NULL));

    int randX, randY;
    char symbol = 'o';

    bool isOverlap = false;

    objPos tempBody;

    

    do
    {
        randX = 1 + (rand() % (boardSizeX - 1));
        randY = 1 + (rand() % (boardSizeY - 1));

        for(int i = 0; i < blockOff->getSize(); i++)
        {
            blockOff->getElement(tempBody, i);
            
            if((tempBody.x == randX) && (tempBody.y == randY))
            {
                isOverlap = true;
                break;
            }
        }

        
    }while(isOverlap);
    foodPos.setObjPos(randX, randY, symbol);


}

void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}


