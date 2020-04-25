#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>

using namespace std;

class GameManager
{
private:
    int time;
    int mines;
    int num;
    bool win;
    int count;

    vector<vector<int> > flags;//0 is close; 1 is open; 2 is mine; 3 is ?
public:
    GameManager();

    void setNum(int n);

    void setTime(int t);

    int getTime();

    void setMines(int m);

    int getMines();

    void initialFlags(int col, int row);

    void setFlag(int x, int y);

    void openFlag(int x, int y);

    int getFlag(int x, int y);

    bool isWin();
};

#endif // GAMEMANAGER_H
