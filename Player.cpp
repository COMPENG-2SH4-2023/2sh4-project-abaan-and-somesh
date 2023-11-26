#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(5, 5, '@');
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
                myDir = DOWN;
            }
            break;

        default:
            break;
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

