	#include "include/raylib.h"
	#define RAYGUI_IMPLEMENTATION
	#include"include/raygui.h"
	#include<math.h>


	// ScreenSize
	const int screenWidth = 500;
	const int screenHeight = 900;
	const bool Window = true;

	// Global Variables
	bool mainMenu = true;
	bool campaignButton = false;
	bool customButton = false;
	bool quitButton = false;
	bool settingsButton = false;
	bool backButton = false;
	bool generateButton = false;
	bool testButton = false;
	int count = 0;
	Vector2 Poly = {50.0f, 50.0f};
	Vector2 PolyPos[] = { 0 };
	Color ColorArr [5] = {RED, GREEN, BROWN, PURPLE, GOLD};
 

	// Structs
	Camera2D camera = 
	{
	.offset = {1.0f, 1.0f},
	.target = {0.0f, 0.0f},
	.rotation = 0.0f,
	.zoom = 2.0f
	};
	Rectangle Rectone = {100, 100, 100, 100};


	//Function declarations
	void RenderScene(void);
	void Init(void);
	void ChangeScene(int value);
	void CameraOffset(void);
	void CameraZoom(void);
	void MainMenu(void);
	void quit(void);
	void DrawScene(void);
	// Vector2 PointyHexagonCorner(Vector2 (center), float size, int i);


	// Functions

	// Vector2 PointyHexagonCorner(Vector2 (center), float size, int i)
	// {
	// 	float AngleDeg = 60 * i - 30;
	// 	float AngleRad = PI / 180 * AngleDeg;
	// 	return  (center.x + size * cos(AngleRad), center.y + size * sin(AngleRad));
	// }

	void Init(void) // Initialization function
	{
		InitWindow(screenWidth, screenHeight, "Ultima Thule");
		SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
		SetExitKey(0);

	} 

	void quit(void) // Close window and OpenGL context
	{
		CloseWindow(); 
	}

	void RenderScene(void) // Main Rendering Function.
	{
		BeginDrawing();
		ClearBackground(WHITE);
		MainMenu();
		DrawFPS(10, 10);
		EndDrawing();
	}

	void CameraZoom(void) //  Camera Zoom Function 
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

	void CameraOffset(void) // Camera Offset Function
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
		if (camera.offset.x>500.0f)
		{
			camera.offset.x = 500.0f;
		}
		if (camera.offset.x<0.0f)
		{
			camera.offset.x = 0.0f;
		}
		if(camera.offset.y>900.0f)
		{
			camera.offset.y = 900.0f;
		}
		if (camera.offset.y<0.0f)
		{
			camera.offset.y = 0.0f;
		}
	}
// Function Discripction

	void ChangeScene(int Value) //Scene changing ie Menu changing Function.
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


	void MainMenu(void) // Main Menu displaying Function
	{
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
				for (int i = 0; i < 5; i++)
				{
				DrawPoly(PolyPos[i], 6, 50.0f, 0.0f, ColorArr[i]);
				}
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
	}

	int main(void)
	{
		Init();

		while (Window) 
		{
			RenderScene();
		}
		quit();
	return 0;
	}


