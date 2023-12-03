#include <iostream>

#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;


objPos myPos;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs();
    myPlayer =  new Player(myGM);

    objPos currentPlayerPos;
    myPlayer->getPlayerPos(currentPlayerPos);

    srand(time(NULL));
    myGM->generateFood(currentPlayerPos);

    //myPos.setObjPos(5, 5, '@');
    
    
}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    if (myGM->getInput() == 27)
    {
        myGM->setExitTrue();
        return;
    }
    objPos currentPlayerPos;
    myPlayer->getPlayerPos(currentPlayerPos);

    if (myGM->getInput() == 9)
    {
        srand(time(NULL));
        myGM->generateFood(currentPlayerPos);
        
    }
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    int x, y;
    objPos currentPlayerPos, currentFoodPos;
    myPlayer->getPlayerPos(currentPlayerPos);
    myGM->getFoodPos(currentFoodPos);


    
    for(y = 0; y <= myGM->getBoardSizeY(); y++)
    {
        for(x = 0; x <= myGM->getBoardSizeX(); x++)
        {
            if(y == 0 || y == myGM->getBoardSizeY())
            {
                
                cout << "#";
                
                
            }

            else if((x == currentPlayerPos.x) && (y == currentPlayerPos.y))
            {
                MacUILib_printf("%c", currentPlayerPos.symbol);
            }

            else if((x == currentFoodPos.x) && (y == currentFoodPos.y))
            {
                MacUILib_printf("%c", currentFoodPos.symbol);
            }

            else
            {
                
                if(x == 0 || x == myGM->getBoardSizeX())
                {
                    
                    cout << "#";
                    
                }

                

                else
                {
                    
                    cout << " ";
                    
                }

                

                
            }            
            
        }
        
        cout << endl;
    }

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);
    
    MacUILib_printf("\nBoardSize: %dx%d, Player Pos: <%d,%d> + %c\n",
                    myGM->getBoardSizeX() + 1, myGM->getBoardSizeY() + 1,
                    tempPos.x,tempPos.y,tempPos.symbol);

    myPlayer->printPlayerDir();

    MacUILib_printf("\nEnter Tab key to regenerate food at new location\n");
    
    /*
    switch(myPlayer->myDir)
    {
        case STOP:
            MacUILib_printf("Current Object State: STOP");
            break;

        case UP:
            MacUILib_printf("Current Object State: UP");
            break;
        
        case DOWN:
            MacUILib_printf("Current Object State: DOWN");
            break;
        
        case LEFT:
            MacUILib_printf("Current Object State: LEFT");
            break;

        case RIGHT:
            MacUILib_printf("Current Object State: RIGHT");
            break;
    }
    */
    
    //printf("\n");
    /*
    printf("Player Object Coordinates: \n", player_object.x, player_object.y);    

    if(last_key_entered)
    {
        printf("Key Pressed: %c\n", last_key_entered);
    }

    else
    {
        printf("Key Pressed: \n");
    }

    switch(object_direction)
    {
        case STOP:
            printf("Object Direction: STOP\n");
            break;
        
        case UP:
            printf("Object Direction: UP\n");
            break;

        case DOWN:
            printf("Object Direction: DOWN\n");
            break;

        case LEFT:
            printf("Object Direction: LEFT\n");
            break;

        case RIGHT:
            printf("Object Direction: RIGHT\n");
            break;
    }

    printf("Game speed: %d micro-seconds per frame\n", game_speed);
    printf("Press '+' to increase speed and '-' to decrease speed\n\n"); 

    printf("Mystery String: ");
    int displayString;
    for(displayString = 0; displayString < goalStringSize - 1; displayString++)
    {
        printf("%c", mysteryString[displayString]);
    }
    printf("\n");
    printf("Move Count: %d", moveCount); 
    */

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    MacUILib_uninit();

    delete myGM;
    delete myPlayer; 
}
