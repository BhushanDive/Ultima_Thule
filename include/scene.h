//-------------------Global Variables----------------------//

extern bool mainMenu;
extern bool campaignButton; 
extern bool customButton;
extern bool quitButton;
extern bool settingsButton;
extern bool backButton;
extern bool generateButton;


//--------------------Functions----------------------------//

void ChangeScene(int Value)
{
    switch (Value)
    {
    case 1:
        mainMenu = false;
        ClearBackground(RED);
        backButton = GuiToggle((Rectangle){100, 800, 50, 50}, "Back", backButton);
          if (backButton)
          {
            mainMenu = !mainMenu;
            campaignButton = !campaignButton;
          }
        break;
    
    default:
        break;
    }
}