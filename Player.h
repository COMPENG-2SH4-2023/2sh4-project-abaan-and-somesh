#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir();
        void movePlayer();
        //need more actions in here:
        //after inserting head but before removing tail
        // - check if new head position collides with food
        // - if yes, increment the score in GM, generate new food and do not remove tail
        //   otherwise, remove tail and move on.



        //Lastly, add self-collision check
        // - if self-collided, set LoseFlag and exitFlag both to true
        //   (through GM)
        //   this will break the program loop and end the game


        // - if ending, you need to differentiate the end game status
        // LOST or just ENDGAME message


        void printPlayerDir();

    private:
        objPosArrayList *playerPosList;   // Upgrade this in iteration 3.       
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif