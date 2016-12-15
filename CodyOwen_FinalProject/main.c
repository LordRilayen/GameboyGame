#include "myLib.h"
//#include "labTiles.h"
#include "StartScreen.h"
//#include "GameScreen.h"
#include "WinScreen.h"


unsigned int buttons;
unsigned int oldButtons;

void splash();
void game();
void win();

int hOffZero;
int vOffZero;

enum {STARTSCREEN, GAMESCREEN, LOSESCREEN, WINSCREEN, PAUSESCREEN};

int state = STARTSCREEN;

int main()
{
    unsigned short* bg0map = (unsigned short*)ScreenBaseBlock(31);
	// ENABLE MODE0 and Background 0
	// Look in myLib.h for the correct #defines
	SetMode(0 | BG0_ENABLE);

	// This is the register that controls background 0
	//   - Background 0 is the front most layer
	// Tell it its size to use, in this case we want 32x32 tiles (256x256 pixels)
	// then tell it which character block to use  
	//   -(character blocks store your tiles)
	// and which screen block to use  
	//   -(screen blocks store the map which determines which tiles are displayed and where)
	// finally enable 256 colors for your background
	REG_BG0CNT = COLOR256 | TEXTBG_SIZE_256x256 | (31 << SCREEN_SHIFT) | WRAPAROUND;
        

	// Load that palette for your tiles into the regular palette memory
        //loadPalette(labTilesPal);

	// Load your tiles into the charblock that your background is using
	//  - We will be using the tiles from the tile sheet provided with this lab
	//DMANow(3, labTilesTiles, &CHARBLOCKBASE[0], (labTilesTilesLen)/2);// | DMA_SOURCE_INCREMENT);

	// We're going to make our own custom map 
	//  - (normally you would let usenti do this part for you)
	// modify this array to display the desired image onto the background
	/*unsigned short bgMap[1024] = 
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 6, 11, 11, 11, 11, 11, 11, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 16, 21, 21, 21, 21, 21, 21, 17, 0, 0, 0, 0, 0, 0, 20, 19, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 12, 10, 10, 10, 10, 10, 10, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };*/

	// Load your tile map into the screenblock that your background is using
	//DMANow(3, bgMap, &SCREENBLOCKBASE[31], 1024);// | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT);
	
	hOffZero = 0;
	vOffZero = 0;

	buttons = BUTTONS;
        
        loadPalette(StartScreenPal);
        DMANow(3, StartScreenTiles, &CHARBLOCKBASE[0], (StartScreenTilesLen)/2);// | DMA_SOURCE_INCREMENT);

	while(1)
	{
		oldButtons = buttons;
		buttons = BUTTONS;

		// these controls let you scroll your background around 
		//if(BUTTON_HELD(BUTTON_LEFT))
		//{
			//hOffZero--;
		//}
		//if(BUTTON_HELD(BUTTON_RIGHT))
		//{
			//hOffZero++;
		//}
		//if(BUTTON_HELD(BUTTON_UP))
		//{
			//vOffZero--;
		//}
		//if(BUTTON_HELD(BUTTON_DOWN))
		//{
			//vOffZero++;
		//}

                switch(state)
                {
                    case STARTSCREEN:
                        splash();
                        break;
                    case GAMESCREEN:
                        game();
                        break;
                    case PAUSESCREEN:
                        break;
                    case WINSCREEN:
                        win();
                        break;
                    case LOSESCREEN:
                        break;
                }
                
		waitForVblank();
		//REG_BG0HOFS = hOffZero;
		//REG_BG0VOFS = vOffZero;
	}
	return 0;
}

void splash()
{
    oldButtons = buttons;
    buttons = BUTTONS;
    
    DMANow(3, StartScreenMap, &SCREENBLOCKBASE[31], 1024);// | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT);
    while(1)
    {
        if(BUTTON_HELD(BUTTON_START))
        {
            loadPalette(WinScreenPal);
            DMANow(3, WinScreenTiles, &CHARBLOCKBASE[0], (WinScreenTilesLen)/2);
            state = WINSCREEN;
        }
    }
    //state = GAMESCREEN;
}

void game()
{
    oldButtons = buttons;
    buttons = BUTTONS;
    
    state = WINSCREEN;
}

void win()
{
    oldButtons = buttons;
    buttons = BUTTONS;
    
    DMANow(3, WinScreenMap, &SCREENBLOCKBASE[31], 1024);
    while(1)
    {
        if(BUTTON_HELD(BUTTON_START))
        {
            loadPalette(StartScreenPal);
            DMANow(3, StartScreenTiles, &CHARBLOCKBASE[0], (StartScreenTilesLen)/2);
            state = STARTSCREEN;
        }
    }
    //state = STARTSCREEN;
}