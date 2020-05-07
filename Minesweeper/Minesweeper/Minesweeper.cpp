// Minesweeper.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Func.h"


int main()
{
    cout << "请输入数字选择难度：1.简单 2.普通 3.困难 (输入数字以外的字符默认简单难度)" << endl;
    int n;
    int m;
    int behavior;
    cin >> n;
    int rows = 9;
    int cols = 9;
    MinesWeeper mw = MinesWeeper(n, rows, cols);
    //Difficulty mode = mw.SelectMode(n, rows, cols);
    srand((int)time(0));
    string **map = new string*[rows];
    mw.EnumInitMap(map, rows, cols);
    mw.EnumMsCreate(map, rows, cols);
    mw.EnumPrint(map, rows, cols);
    mw.UpdateMap(map, rows, cols);
    for (;!mw.IsLose && !mw.IsWin;)
    {
        cout << "请输入数字选择对应的行为：1.打开格子 2.标记雷的位置 3.撤销标记 4.排雷" << endl;
        cin >> behavior;
        if (behavior == 1)
        {
            cout << "请输入要打开的格子对应的行数（回车确定）：" << endl;
            cin >> m;
            cout << "请输入要打开的格子对应的列数（回车确定）：" << endl;
            cin >> n;
            mw.OpenMap(map, m-1, n-1);
            mw.UpdateMap(map, rows, cols);
        }
        if (behavior == 2)
        {
            cout << "请输入要标记的格子对应的行数（回车确定）：" << endl;
            cin >> m;
            cout << "请输入要标记的格子对应的列数（回车确定）：" << endl;
            cin >> n;
            mw.SignMs(m-1, n-1);
            mw.UpdateMap(map, rows, cols);
        }
        if (behavior == 3)
        {
            cout << "请输入要撤销标记的格子对应的行数（回车确定）：" << endl;
            cin >> m;
            cout << "请输入要撤销标记的格子对应的列数（回车确定）：" << endl;
            cin >> n;
            mw.SignMsVoke(m - 1, n - 1);
            mw.UpdateMap(map, rows, cols);
        }
        if (behavior == 4)
        {
            cout << "请输入要排雷的格子对应的行数（回车确定）：" << endl;
            cin >> m;
            cout << "请输入要排雷的格子对应的列数（回车确定）：" << endl;
            cin >> n;
            mw.MsJudge(map, m - 1, n - 1);
            mw.UpdateMap(map, rows, cols);
        }
    }
}


