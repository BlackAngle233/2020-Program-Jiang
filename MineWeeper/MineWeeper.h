#ifndef MINEWEEPER_H
#define MINEWEEPER_H

#endif // MINEWEEPER_H

#include <vector>

using namespace std;

static int x_offset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
static int y_offset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

class MineWeeper {
private:
    int col;
    int row;
    vector<vector<int> > board;//0 is null; 1~8 is num; 9 is mine

    void MineInitialize(int n);
    void NumInitialize();
public:
    MineWeeper() {
        this->col = 0;
        this->row = 0;
    }

    void newMineWeeper(int c, int r, int n);

    bool checkMine(int x, int y);

    bool checkNum(int x, int y);

    bool checkEmpty(int x, int y);

    bool isValid(int x, int y);

    int getNum(int x, int y);
};
