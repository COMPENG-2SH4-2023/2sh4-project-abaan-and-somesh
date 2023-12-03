#include "Player.h"
#include "MacUILib.h"

#include <ctime>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2 + 1, 
                       mainGameMechsRef->getBoardSizeY()/2 + 1, '*');

    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

    



}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic   
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'w':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = UP;
            }
            break;

        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 's':
            if(myDir != UP && myDir != DOWN)
            {
                myDir = DOWN;
            }
            break;
        
        case 'd':
            if(myDir != LEFT && myDir != RIGHT)
            {
                myDir = RIGHT;
            }
            break;

        default:
            break;
    }     
}

void Player::movePlayer()
{
    //objPos newHead;
    objPos currHead;
    playerPosList->getHeadElement(currHead);


    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case UP:
            currHead.y--;
            if(currHead.y < 1)
            {
                currHead.y = mainGameMechsRef->getBoardSizeY() - 1;
            }
            break;
        
        case LEFT:
            currHead.x--;
            if(currHead.x < 1)
            {
                currHead.x = mainGameMechsRef->getBoardSizeX() - 1;
            }
            break;

        case DOWN:
            currHead.y++;
            if(currHead.y > mainGameMechsRef->getBoardSizeY() - 1)
            {
                currHead.y = 1;
            }
            break;

        case RIGHT:
            currHead.x++;
            if(currHead.x > mainGameMechsRef->getBoardSizeX() - 1)
            {
                currHead.x = 1;
            }
            break;

        case STOP:
        default:
            break;
    }

    if(mainGameMechsRef->getScore() != 0)
    {

    
        objPosArrayList* body = getPlayerPos();
        objPos tempBody;

        for(int k = 0; k < body->getSize(); k++)
        {
            body->getElement(tempBody, k);
            if((tempBody.x == currHead.x) && (tempBody.y == currHead.y))
            {
                mainGameMechsRef->setLoseTrue();
                mainGameMechsRef->setExitTrue();
                return;
            }
        }
    }



    //new currHead should be added to playerPosList head
    playerPosList->insertHead(currHead);

    objPos currFoodPos;
    mainGameMechsRef->getFoodPos(currFoodPos);

    if((currHead.x == currFoodPos.x) && (currHead.y == currFoodPos.y))
    {
        objPosArrayList* playerBody = getPlayerPos();
        mainGameMechsRef->generateFood(playerBody);
        mainGameMechsRef->incrementScore();

    }

    else
    {
        //remove playerPosList tail
        playerPosList->removeTail();

    }

    
}

void Player::printPlayerDir()
{
    switch(myDir)
    {
        case UP:
            
            MacUILib_printf("\nCurrent Object Direction: UP\n");
            break;
        
        case LEFT:
            MacUILib_printf("\nCurrent Object Direction: LEFT\n");
            break;

        case DOWN:
            MacUILib_printf("\nCurrent Object Direction: DOWN\n");
            break;

        case RIGHT:
            MacUILib_printf("\nCurrent Object Direction: RIGHT\n");
            break;

        case STOP:
            MacUILib_printf("\nCurrent Object Direction: STOP\n");
            break;

        default:
            break;
    }
}
