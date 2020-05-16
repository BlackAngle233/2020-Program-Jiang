#include "GameManager.h"
#include <stdlib.h>
#include <time.h>
#include <queue>
void GameManager::initmap(Difficulty _difficulty)
{
    int Table[] {40, 60, 80};
    map.resize(Table[_difficulty]);
    inQueue.resize(Table[_difficulty]);
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        it -> resize(Table[_difficulty]);
    }

    for(auto it = inQueue.begin(); it != inQueue.end(); ++it)
    {
        it -> resize(Table[_difficulty]);
    }
}

bool GameManager::islegal(int x,int y)
{
    bool xlegal = x >= 0 && x < xbound;
    bool ylegal = y >= 0 && y < ybound;
    return xlegal && ylegal;
}


void GameManager::burymines()
{
    switch(this -> difficulty)
    {
        case easy:
            UnExplodedMineNumber = 20;
            break;
        case normal:
            UnExplodedMineNumber = 40;
            break;
        case hard:
            UnExplodedMineNumber = 60;
            break;
    }

    srand(time(NULL));
    int x,y;
    int mine = 0;
    while(mine < UnExplodedMineNumber)
    {
        x = rand() % xbound;
        y = rand() % ybound;
        if(map[x][y] == 0)
        {
            ++mine;
            map[x][y] = 9;
        }
    }
    
}


int GameManager::CalculateMines(int x, int y)
{
    int nx=0,ny=0;
   int ans = 0;
    for(int i = 0; i < 8; ++i)
    {
        nx = x + dirx[i];
        ny = y + diry[i];
        if(!islegal(x,y)) continue;
        if(map[nx][ny] == 9)
        {
            ++ans;
        }
    }
    return ans;
}



void GameManager::burynumbers()
{
    for(int i = 0; i < xbound; ++i)
    {
        for(int j = 0; i < ybound; ++i)
        {
            int minenumber = CalculateMines(i,j);
            if(map[i][j] != 9) map[i][j] = minenumber;
        }
    }
}


bool GameManager::isSuitable(int x,int y)
{
    bool islegalxy = islegal(x,y);
    bool isNumberOrMine = map[x][y] > 0 ? true : false;
    return islegalxy && !isNumberOrMine && !inQueue[x][y];
}



int GameManager::ExplodePoint(int x,int y)
{
    //use bfs to search.
    std::queue<struct point> q;
    struct point nowPos {x,y};
    q.push(nowPos);
    if(isSuitable(x,y)) return -1;
    else
    {
        while(!q.empty())
        {
            struct point top = q.front();
            inQueue[top.x][top.y] = true;
            q.pop();
            for(int i= 0; i < 8; ++i)
            {
                int newX = top.x + dirx[i];
                int newY = top.y + diry[i];
                if(isSuitable(newX,newY))
                {
                    struct point temp{newX,newY};
                    q.push(temp);
                }
            }
        }
        return 1;
    }
}


void GameManager::run()
{
    this -> sManager -> update();

    while(1)
    {
        char ch = getch();
        switch(ch)
        {
            case KEY_LEFT:
                sManager -> movecursor(-1,0);
                break;
            case KEY_RIGHT:
                sManager -> movecursor(1,0);
                break;
            case KEY_UP:
                sManager -> movecursor(0,-1);
                break;
            case KEY_DOWN:
                sManager -> movecursor(-1, 0);
                break;
            case KEY_EXIT:
                exit(0);
                break;
        }
        sManager -> update();
    }
}




