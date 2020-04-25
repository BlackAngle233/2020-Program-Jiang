#include "MineWeeper.h"
#include <cstdlib>
#include <ctime>

void MineWeeper::newMineWeeper(int c, int r, int n) {
    if(col != 0 && row != 0) {
        for(int i = 0; i < col; ++i) {
            board[col].clear();
        }
        board.clear();
    }

    this->col = c;
    this->row = r;
    for(int i = 0; i < col; ++i) {
        vector<int> tmp;
        for(int j = 0; j < row; ++j) {
            tmp.push_back(0);
        }
        this->board.push_back(tmp);
    }
    MineInitialize(n);
    NumInitialize();
}

void MineWeeper::MineInitialize(int n) {
    srand((int)time(0));

    int randx = 0;
    int randy = 0;

    for(int i = 0; i < n; ++i) {
        randx = (rand() % this->col);
        randy = (rand() % this->row);
        if(!checkMine(randx, randy)) {
            board[randy][randx] = 9;
        }
        else {
            i--;
        }
    }

}

void MineWeeper::NumInitialize() {
    for(int i = 0; i < col; ++i) {
        for(int j = 0; j < row; ++j) {
            if(!checkMine(i, j)) {
                int num = 0;
                for(int k = 0; k < 8; k++) {
                    if(checkMine(i + x_offset[k], j + y_offset[k])) {
                        num++;
                    }
                }
                board[i][j] = num;
            }
        }
    }
}

bool MineWeeper::checkMine(int x, int y) {
    if(x < 0 || x >= this->col || y < 0 || y >= this->row)
        return false;
    if(board[x][y] == 9)
        return true;
    return false;
}

bool MineWeeper::checkNum(int x, int y) {
    if(x < 0 || x >= this->col || y < 0 || y >= this->row)
        return false;
    if(board[x][y] > 0 && board[x][y] < 9)
        return true;
    return false;
}

bool MineWeeper::checkEmpty(int x, int y) {
    if(x < 0 || x >= this->col || y < 0 || y >= this->row)
        return false;
    if(board[x][y] == 0)
        return true;
    return false;
}

bool MineWeeper::isValid(int x, int y) {
    if(x < 0 || x >= this->col || y < 0 || y >= this->row)
        return false;
    return true;
}

int MineWeeper::getNum(int x, int y) {
    return board[x][y];
}
