#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2 + 1, 
                        mainGameMechsRef->getBoardSizeY()/2 + 1, '*');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
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
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case UP:
            playerPos.y--;
            if(playerPos.y < 1)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 1;
            }
            break;
        
        case LEFT:
            playerPos.x--;
            if(playerPos.x < 1)
            {
                playerPos.x = mainGameMechsRef->getBoardSizeX() - 1;
            }
            break;

        case DOWN:
            playerPos.y++;
            if(playerPos.y > mainGameMechsRef->getBoardSizeY() - 1)
            {
                playerPos.y = 1;
            }
            break;

        case RIGHT:
            playerPos.x++;
            if(playerPos.x > mainGameMechsRef->getBoardSizeX() - 1)
            {
                playerPos.x = 1;
            }
            break;

        default:
            break;
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
