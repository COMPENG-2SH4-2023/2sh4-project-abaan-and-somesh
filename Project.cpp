#include <iostream>

#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define max_board_height 9
#define max_board_width 19

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

    myGM = new GameMechs(26,13);
    myPlayer =  new Player(myGM);

    myPos.setObjPos(5, 5, '@');

    
}

void GetInput(void)
{
   myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    int x, y;
    
    for(y = 0; y <= max_board_height; y++)
    {
        for(x = 0; x <= max_board_width; x++)
        {
            if(y == 0 || y == max_board_height)
            {
                
                cout << "#";
                
                
            }

            else
            {
                
                if(x == 0 || x == max_board_width)
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
    MacUILib_printf("BoardSize: %dx%d, Player Pos: <%d,%d> + %c\n",myGM->getBoardSizeX(),myGM->getBoardSizeY(),tempPos.x,tempPos.y,tempPos.symbol);
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
}
