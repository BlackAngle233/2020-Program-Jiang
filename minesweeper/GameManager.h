#ifndef _GM_MANAGER_H
#define _GM_MANAGER_H

#include <vector>
#include "ScreenManager.h"
//difficulty is a enum class with easy normal,hard

class GameManager 
{
    private:
        int Score = 0;
        int xbound,ybound;

        int UnExplodedMineNumber;

        enum Difficulty difficulty;

        //for basic map storage
        const int maxn = 110;

        //in this map, 0 means there is no mines at this point, 9 means there is a mine, 
        //if map[x][y] is a number in the range 1 to 8, that means 
        std::vector<std::vector<int>> map;
        std::vector<std::vector<bool>> inQueue; //used in click one pos;
        void initmap(enum Difficulty _difficulty);

        //Game Logic Implementations
        struct point {int x;int y;};

        //randomly generate mines until the number of the mines reach the upperbound we set 
        void burymines();

        //to judge if a point is a legal point
        bool islegal(int x,int y);

        //Calculate how many mines around the given point
        int CalculateMines(int x,int y);

        //To Set Numbers on this map
        int SetNumbers(int xbound, int ybound);

        void burynumbers();

        //To implement the one-click event
        int ExplodePoint(int x, int y);

        int dirx[8]  {1,1,0,-1,-1,-1,0,1};
        int diry[8]  {0,-1,-1,-1,0,1,1,1};
 
        //To judge if the point is suitable to explode
        bool isSuitable(int x, int y);

        //UIManager: a function set to manage basic ui
        ScreenManager *sManager = nullptr;


    public:
        GameManager(Difficulty _difficulty)
        {
            switch(_difficulty)
            {
                case easy:
                    xbound = 40;
                    ybound = 25;
                    break;
                case normal:
                    xbound = 60;
                    ybound = 35;
                    break;

                case hard:
                    xbound = 80;
                    ybound = 55;
                    break;
            }
            Score = 0;
            difficulty = _difficulty;
            initmap(_difficulty);
            sManager = new ScreenManager(&map,&inQueue,difficulty);
        }

        ~GameManager()
        {
            delete(sManager);
        }

        void run();

};

#endif
