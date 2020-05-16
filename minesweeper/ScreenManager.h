#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include <vector>
#include <curses.h>

enum Difficulty {easy, normal,hard};
class ScreenManager
{
    public:
        void init();
        void drawmap(int xsize, int ysize);
        void update();
        void movecursor(int dirx, int diry);
        ScreenManager(std::vector<std::vector<int>>* pMap, std::vector<std::vector<bool>>* _pInQueue,Difficulty _difficulty)
        {
            this -> pMap = pMap;
            this -> pInQueue = _pInQueue;
            switch(_difficulty)
            {
                case easy:
                    xsize= 40;
                    ysize= 25;
                    break;
                case normal:
                    xsize= 60;
                    ysize= 35;
                    break;

                case hard:
                    xsize= 80;
                    ysize = 55;
                    break;
            }

            init();
        }

        ~ScreenManager()
        {
            endwin();
        }

        
    private:
        int xsize=0, ysize=0;
        int x=2,y=2; //cursor position
        int ConvertPoint(int x,int y);
        std::vector<std::vector<int>>* pMap;
        std::vector<std::vector<bool>>* pInQueue;
};
#endif


