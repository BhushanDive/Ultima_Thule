#include "include/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include"include/raygui.h"

 // Global Variables
 bool mainMenu = true;
 bool campaignButton = false;
 bool customButton = false;
 bool quitButton = false;
 bool settingsButton = false;
 bool backButton = false;
 bool generateButton = false;

//---------------------Function Declaration------------//
 void ChangeScene(int value);


int main(void)
{
 // ScreenSize
 const int screenWidth = 500;
 const int screenHeight = 900;

    // Initialization
  InitWindow(screenWidth, screenHeight, "A Hex based strategy game");

  SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
{
    // Update  TODO: Update your variables here
        
        // Draw
    BeginDrawing();
   
        ClearBackground(WHITE);

            DrawFPS(10, 10);

            if (mainMenu)
            {
              backButton = false;
              campaignButton = GuiToggle((Rectangle){200, 150, 100, 50},"Campaign", campaignButton);       //Campaign Button Drawing
              customButton = GuiToggle((Rectangle){200, 300, 100, 50},"Custom", customButton);             //Custom Button Drawing
              settingsButton = GuiToggle((Rectangle){200, 450, 100, 50},"Settings", settingsButton);       //Settings Button Drawing 
              quitButton = GuiToggle((Rectangle){200, 600, 100, 50},"Quit", quitButton);                  //Quit Button Drawing
            }

            if (campaignButton)
            {
              ChangeScene(1);
            }
			if (customButton)
            {
				ChangeScene(2);
            }
			if (generateButton)
			{
				ChangeScene(3);
			}
			if (settingsButton)
			{
				ChangeScene(4);
			}
			if (quitButton)
			{
				ChangeScene(5);
			}
			
			
            
            
            
             
                                   
             
        EndDrawing();
        
    }


    //Function Declaration
    

    //DeInilization
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

 return 0;
}


void ChangeScene(int Value)
{
    switch (Value)
    {
    case 1:																			// Campaign Button
        mainMenu = false;
        ClearBackground(RED);
        backButton = GuiToggle((Rectangle){100, 800, 50, 50}, "Back", backButton);
          if (backButton)
          {
            mainMenu = !mainMenu;
            campaignButton = !campaignButton;
          }
        break;

    case 2:																			// Custom Button
		mainMenu = false;
        ClearBackground(BLUE);
        backButton = GuiToggle((Rectangle){100, 800, 50, 50}, "Back", backButton);
        generateButton  = GuiToggle((Rectangle){200, 500, 100, 50},"Generate", generateButton);
          if (backButton)
          {
            mainMenu = !mainMenu;
            customButton = !customButton;
          }
		break;

	case 3:																			// Generate Button
	 	mainMenu = false;
        customButton = false;
        ClearBackground(GREEN);
		backButton = GuiToggle((Rectangle){100, 800, 50, 50}, "Back", backButton);
		  if (backButton)
		  {
			  generateButton = !generateButton;
			  customButton = !customButton;
		  }
		break;

	case 4:																			// Setting Button
		mainMenu = false;
		ClearBackground(BLACK);
		backButton = GuiToggle((Rectangle){100, 800, 50, 50}, "Back", backButton);
		  if (backButton)
		  {
			  mainMenu = !mainMenu;
			  settingsButton = !settingsButton;
		  }
		break;
	
	case 5:																			// Quit Button 
		CloseWindow();
    
    default:
        break;
    }
}