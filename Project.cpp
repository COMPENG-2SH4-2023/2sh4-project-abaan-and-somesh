#include <iostream>

#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"


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
    currentPlayerPos.setObjPos(-1, -1, 'o');

    objPosArrayList* playerBody = myPlayer->getPlayerPos();

    

    srand(time(NULL));
    myGM->generateFood(playerBody);

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

    

    
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   

    bool drawn;

    int x, y;
    
    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;
    
    objPos currentFoodPos;
    myGM->getFoodPos(currentFoodPos);


    
    for(y = 0; y <= myGM->getBoardSizeY(); y++)
    {
        for(x = 0; x <= myGM->getBoardSizeX(); x++)
        {
            drawn = false;

            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempBody, k);
                if((tempBody.x == x) && (tempBody.y == y))
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;

            if(y == 0 || y == myGM->getBoardSizeY())
            {
                
                cout << "#";
                
                
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

    
    
    
    

    

    MacUILib_printf("\nScore: %d\n", myGM->getScore());
    myPlayer->printPlayerDir();
    
    objPos currentHeadPos;
    playerBody->getElement(currentHeadPos, 0);
    MacUILib_printf("\nCurrent Head position: <%d, %d>\n", currentHeadPos.x, currentHeadPos.y);

    
    
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if(myGM->getLoseFlagStatus())
    {
        MacUILib_printf("\nYou Lose !! you crashed the snake into itself\n");
    }
    else
    {
        MacUILib_printf("\nYou quit\n");
    }
    MacUILib_printf("\n Your final score was: %d\n", myGM->getScore());
    
    MacUILib_uninit();
    

    delete myGM;
    delete myPlayer; 
}
