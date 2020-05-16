#include "ScreenManager.h"
#include <curses.h>

void ScreenManager::init()
{
    initscr();
    cbreak();
    noecho();
    raw();
    keypad(stdscr,TRUE);
}

void ScreenManager::drawmap(int xsize, int ysize)
{
   this -> xsize = xsize; this -> ysize= ysize;
   mvhline(0,0,'#', xsize+2); 
   mvvline(1,0,'#',ysize+1);
   mvvline(1,xsize+1, '#', ysize+1);
   mvhline(ysize+1, 0,'#',xsize+1);
   for(int i = 0; i < xsize; ++i)
   {
       for(int j = 0; j < ysize; ++j)
       {
           int number = (*pMap)[i][j];
           if(number == 0 && !(*pInQueue)[i][j])
           {
               mvaddch(j+1,i+1,'.');
           }
           else if(number == 9 && (*pInQueue)[i][j])
           {
               mvaddch(j+1,i+1,'*');
           }
           else 
           {
               mvaddch(j+1,i+1,number+'0');
           }
       }
   }
   //还原光标位置
   move(y,x);
}


void ScreenManager::movecursor(int dirx, int diry)
{
    //判断移动是否合法
    bool isillegal = x+dirx < 2 || x+dirx > xsize-1 || y+diry < 2 || y+diry > ysize;
    if(!isillegal)
    {
        x += dirx;
        y += diry;
        move(y + diry,x + dirx);
    }
}

//进行坐标更新
void ScreenManager::update()
{
    drawmap(xsize,ysize);
    refresh();
}




