#include "include/raylib.h"
#define RAYGUI_IMPLEMENTATION
#include"include/raygui.h"


 // ScreenSize
 const int screenWidth = 500;
 const int screenHeight = 900;

 // Global Variables
 bool mainMenu = true;
 bool campaignButton = false;
 bool customButton = false;
 bool quitButton = false;
 bool settingsButton = false;
 bool backButton = false;
 bool generateButton = false;
 bool testButton = false;
 Texture2D beach;
 

 // Structs
 Camera2D camera = 
 {
   .offset = {1.0f, 1.0f},
   .target = {0.0f, 0.0f},
   .rotation = 0.0f,
   .zoom = 2.0f
 };
 Rectangle Rectone = {100, 100, 100, 100};


//Function eclarations
 void ChangeScene(int value);
 void CameraOffset(void);
 void CameraZoom(void);


int main(void)
{

  
    // Initialization
  InitWindow(screenWidth, screenHeight, "Ultima Thule");
  Texture2D beach = LoadTexture("./Assets/sea.png");

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
    BeginMode2D(camera);

          CameraZoom();

          CameraOffset();

    EndMode2D();
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
    
    UnloadTexture(beach);
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

    	ClearBackground(WHITE);
         
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
		break;
    
    default:
        break;
    }

}
void CameraOffset(void)
{
  if (IsKeyDown(KEY_D))
  {
    camera.offset.x += 2.0f;
  }
  if (IsKeyDown(KEY_A))
  {
    camera.offset.x -= 2.0f;
  }
  if (IsKeyDown(KEY_S))
  {
    camera.offset.y += 2.0f;
  }
  if (IsKeyDown(KEY_W))
  {
    camera.offset.y -= 2.0f;
  }
  if (camera.offset.x>300.0f)
  {
    camera.offset.x = 300.0f;
  }
  if (camera.offset.x<-300.0f)
  {
    camera.offset.x = -300.0f;
  }
  
  
}
void CameraZoom(void)
{
  camera.zoom += ((float)GetMouseWheelMove()*0.05f);
  if (camera.zoom>2.0f)
  {
    camera.zoom = 2.0f;
  }
  if (camera.zoom<0.3f)
  {
    camera.zoom = 0.3f;
  }
}
