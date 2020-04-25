#include "gamemanager.h"

GameManager::GameManager()
{
    count = 0;
}

void GameManager::setNum(int n) {
    this->num = n;
}

void GameManager::setTime(int t) {
    this->time = t;
}

int GameManager::getTime() {
    return this->time;
}

void GameManager::setMines(int m) {
    this->mines = m;
}

int GameManager::getMines() {
    return this->mines;
}

void GameManager::initialFlags(int col, int row) {
    if(!flags.empty()) {
        for(int i = 0; i < flags.size(); ++i) {
            flags[col].clear();
        }
        flags.clear();
    }

    for(int i = 0; i < col; ++i) {
        vector<int> tmp;
        for(int j = 0; j < row; ++j) {
            tmp.push_back(0);
        }
        this->flags.push_back(tmp);
    }
}

void GameManager::setFlag(int x, int y) {
    if(flags[x][y] == 0) {
        mines --;
        flags[x][y] = 2;
    }
    else if(flags[x][y] == 2) {
        mines ++;
        flags[x][y] = 3;
    }
    else if (flags[x][y] == 3)
        flags[x][y] = 0;
}

void GameManager::openFlag(int x, int y) {
    flags[x][y] = 1;
    count ++;
}

int GameManager::getFlag(int x, int y) {
    return flags[x][y];
}

bool GameManager::isWin() {
    return count == num;
}
