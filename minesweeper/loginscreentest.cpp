#include <iostream>
#include <curses.h>


#define EMPTY .
#define MINEBOOM X

void draw_map(int xsize, int ysize)
{
   mvhline(1,1,'#', xsize); 
   mvvline(2,1,'#',ysize-1);
   mvvline(2,xsize, '#', ysize-1);
   mvhline(ysize, 1,'#',xsize);
   for(int i = 2; i < ysize; ++i)
   {
       mvhline(i,2,'.',xsize-2);
   }
}

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr,TRUE);


    draw_map(40,20);
    char ch;

    int x=0, y=0;
	
	

    return 0;
}

    
