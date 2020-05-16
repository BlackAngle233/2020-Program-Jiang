#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 100;

int mine = 0;
int map[maxn][maxn];
bool inQueue[maxn][maxn];


int dirx[] = {1,1,0,-1,-1,-1,0,1};
int diry[] = {0,-1,-1,-1,0,1,1,1};

void burymines()
{
    srand(time(NULL));
    int x,y;
    while(mine <= 10)
    {
        x = rand() % 10;
        y = rand() % 10;
        if(map[x][y] == 0)
        {
            ++mine;
            map[x][y] = 9; //Here is a mine
        }
    }
}

struct point
{
    int x=0,y=0;
};


bool islegal(int x,int y)
{
    bool xlegal = x >= 0 && x < 10;
    bool ylegal = y >= 0 && y < 10;
    return xlegal && ylegal;
}

int Calmines(int x,int y)
{
    int nx,ny;
    int ans = 0;
    for(int i = 0; i < 8; i++)
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


void burynumbers()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            int mineNumber = Calmines(i,j);
            if(map[i][j] != 9) map[i][j] = mineNumber;
        }
    }
}



void init()
{
    fill((int *)map, (int*)map + maxn*maxn, 0);
    burymines();
    burynumbers();

}


void print()
{
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            if(map[i][j] == 10)
            {
                cout << ' ' << ' ';
            }
            else
            {
                cout << map[i][j] << ' ';
            }
            if(i == 9) cout << endl;
        }
    }
}


bool isSuitable(int x,int y)
{
    bool islegalxy = islegal(x,y);
    bool isNumberOrMine = map[x][y] > 0 ? true : false;
    return islegalxy && !isNumberOrMine && !inQueue[x][y];
}


int bfs(int x,int y)
{
    queue<struct point> q;
    struct point nowPos{x,y};
    q.push(nowPos);
    inQueue[x][y] = true;
    if(isSuitable(x,y)) return -1;
    else
    {
        while(!q.empty())
        {
            struct point top = q.front();
            map[top.x][top.y] = 10;
            inQueue[top.x][top.y] = true;
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int newX = top.x + dirx[i];
                int newY = top.y + diry[i];
                if(isSuitable(newX,newY))
                {
                    struct point temp {newX,newY};
                    q.push(temp);
                }
            }
        }
        return 1;
    }
}

int main()
{
    init();
    print();

    cout << "------------------" << endl;
    bfs(1,1);
    print();
}


