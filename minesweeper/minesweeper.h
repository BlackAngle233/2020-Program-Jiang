#include <iostream>
#include<stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
struct minesweeperTable
{
    bool mineFlag;          //0代表没有雷,1代表有雷
    bool openFlag;          //0代表没有打开,1代表打开
    int mines;          //代表周围的雷数
    minesweeperTable()
    {
        mineFlag = false;
        openFlag = false;
        mines = -1;
    }
};

class minesweeper
{
    minesweeperTable table[7][7];
    int mines;
    int iF, jF; //记录第一次输入的坐标
    int bombI, bombJ; //记录爆炸位置
    bool gameState;
    int getDiff()       //选取难度
    {
        int i;
        cout << "请选择难度:" << '\n'
             << "1.简单" << '\n'
             << "2.普通" << '\n'
             << "3.困难" << endl;
        cin >> i;
        return i;
    }

    void setMines(int i)    //设置地雷
    {
        switch (i)
        {
        case 1:
            mines = 12;
            break;
        case 2:
            mines = 24;
            break;
        case 3:
            mines = 34;
            break;
        default:
            mines = 5;
            break;
        }
        int q = 0,ii,j;
        srand((int)time(0));  // 产生随机种子 
        while(q<mines)
        {
            ii = rand() % 7;
            j = rand() % 7;
            if(table[ii][j].mineFlag == false && table[ii][j].openFlag==false)
            {
                table[ii][j].mineFlag = true;
                q++;
                continue;
            }
        }
    }
    
    void setMinesNum()      //设置周围雷数
    {
        int num = 0;
        for (int i = 0; i < 7;i++)
        {
            for (int j = 0; j < 7;j++)          //计算周围雷的数量
            {
                num = 0;
                if(table[i][j].mineFlag==1)
                    continue;
                if(i>0)
                    if(table[i-1][j].mineFlag==true)
                        num++;
                if(i<6)
                    if(table[i+1][j].mineFlag==true)
                        num++;
                if(j>0)
                    if(table[i][j-1].mineFlag==true)
                        num++;
                if(j<6)
                    if(table[i][j+1].mineFlag==true)
                        num++;
                if(i>0 and j>0)
                    if(table[i-1][j-1].mineFlag==true)
                        num++;
                if(i>0 and j<6)
                    if(table[i-1][j+1].mineFlag==true)
                        num++;
                if(i<6 and j>0)
                    if(table[i+1][j-1].mineFlag==true)
                        num++;
                if(i<6 and j<6)
                    if(table[i+1][j+1].mineFlag==true)
                        num++;
                table[i][j].mines = num;
            }
        }
    }

    void checkZ(int i,int j)//检查展开格子
    {
        if(table[i][j].mineFlag==true)
            return;
        if(table[i][j].mines==0  )
        {
            if(i>0)
                if(table[i-1][j].mineFlag==0 && table[i-1][j].openFlag==false)
                    open(i - 1, j);
            if(i<6)
                if(table[i+1][j].mineFlag==0&& table[i+1][j].openFlag==false)
                    open(i + 1, j);
            if(j>0)
                if(table[i][j-1].mineFlag==0&& table[i][j-1].openFlag==false)
                    open(i, j - 1);
            if(j<6)
                if(table[i][j+1].mineFlag==0&& table[i][j+1].openFlag==false)
                    open(i, j + 1);
            if(i>0 and j>0)
                if(table[i-1][j-1].mineFlag==0&& table[i-1][j-1].openFlag==false)
                    open(i - 1, j - 1);
            if(i>0 and j<6)
                if(table[i-1][j+1].mineFlag==0&& table[i-1][j+1].openFlag==false)
                    open(i - 1, j + 1);
            if(i<6 and j>0)
                if(table[i+1][j-1].mineFlag==0&& table[i+1][j-1].openFlag==false)
                    open(i + 1, j - 1);
            if (i < 6 and j < 6)
                if(table[i+1][j+1].mineFlag==0&& table[i+1][j+1].openFlag==false)
                    open(i + 1, j + 1);
        }
    }
    void check(int i, int j)    //检查格子
    {
        if(table[i][j].mineFlag==true)
        {
            bombI = i;
            bombJ = j;
            gameState = false;
            return;
        }
        if (table[i][j].mines == 0 )
        {
           
             if(i>0)
                if(table[i-1][j].mineFlag==0 && table[i-1][j].openFlag==false)
                    open(i - 1, j);
            if(i<6)
                if(table[i+1][j].mineFlag==0&& table[i+1][j].openFlag==false)
                    open(i + 1, j);
            if(j>0)
                if(table[i][j-1].mineFlag==0&& table[i][j-1].openFlag==false)
                    open(i, j - 1);
            if(j<6)
                if(table[i][j+1].mineFlag==0&& table[i][j+1].openFlag==false)
                    open(i, j + 1);
            if(i>0 and j>0)
                if(table[i-1][j-1].mineFlag==0&& table[i-1][j-1].openFlag==false)
                    open(i - 1, j - 1);
            if(i>0 and j<6)
                if(table[i-1][j+1].mineFlag==0&& table[i-1][j+1].openFlag==false)
                    open(i - 1, j + 1);
            if(i<6 and j>0)
                if(table[i+1][j-1].mineFlag==0&& table[i+1][j-1].openFlag==false)
                    open(i + 1, j - 1);
            if (i < 6 and j < 6)
                if(table[i+1][j+1].mineFlag==0&& table[i+1][j+1].openFlag==false)
                    open(i + 1, j + 1);
        }
    }

    void gameOver()
    {
        system("cls");
        test();
        cout << "你死于(" << bombI+1 << ',' << bombJ+1 << ")处的地雷,";
        cout << "游戏结束!"<<endl;
        system("pause");
    }

    bool winCheck()
    {
        int num;
        for (int i; i < 7;i++)
            for (int j; j < 7;j++)
            {
                if(table[i][j].openFlag==0)
                    num++;
            }
        if (num ==mines)
        {
            cout << "You win!" << endl;
            return true;
        }
        return false;
    }
     void printTable()       //打印界面
    {
        cout << ' '<<'\t';
        for (int i = 1; i <= 7;i++)
            cout << i << '\t';
        cout << '\n';
        for (int i = 0; i < 7; i++)
        {
            cout << i + 1 << '\t';
            for (int j = 0; j < 7; j++)
            {
                if (table[i][j].openFlag == 0)
                    cout << "□" << '\t';
                else if (table[i][j].mineFlag == 1)
                    cout << "*"<< '\t';
                else
                    cout << table[i][j].mines<< '\t';
            }
            cout << '\n';
        }
    }

    void openF()     //第一次的打开某一格
    {
        cout << "请输入要打开的格子的坐标:";
        cin >> iF >> jF;
        if (iF < 1 || iF > 7 || jF < 1 || jF>7)
        {
            cout << "请输入两个1-7的值" << endl;
            openF();
            return;
        }
        table[iF-1][jF-1].openFlag = true;
    }
    
    void open()        //打开某一格
    {
        cout << "请输入要打开的格子的坐标:";
        int i, j;
        cin >> i >> j;
        if (i < 1 || i > 7 || j < 1 || j>7)
        {
            cout << "请输入两个1-7的值" << endl;
            openF();
            return;
        }
        table[i-1][j-1].openFlag = true;
        check(i-1, j-1);
    }
    void open(int i, int j)
    {
        table[i][j].openFlag = true;
        checkZ(i, j);
    }

    public:
    minesweeper() 
    {
        bombI = -1;
        bombJ = -1;
        int Diff;
        gameState = true;
        Diff=getDiff();
        system("cls");
        printTable();
        openF();
        setMines(Diff);
        setMinesNum();
        checkZ(iF-1,jF-1);
    }

    void onPlay()
    {
        for (;;)
        {
            system("cls");
            printTable();
            open();
            if(gameState==false)
            {   
                gameOver();
                break;
            }
            if(winCheck())
                break;
        }
        
    }

   void test()
   {
       cout << ' '<<'\t';
        for (int i = 1; i <= 7;i++)
            cout << i << '\t';
        cout << '\n';
        for (int i = 0; i < 7; i++)
        {
            cout << i + 1 << '\t';
            for (int j = 0; j < 7; j++)
            {
                if (table[i][j].mineFlag == 1)
                    cout << "*"<< '\t';
                else
                    cout << table[i][j].mines<< '\t';
            }
            cout << '\n';
        }
   }

   

};