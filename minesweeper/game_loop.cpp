#include "GameManager.h"
#include "ScreenManager.h"



int main()
{
    GameManager *gManager = new GameManager(easy);
    gManager -> run();
}
