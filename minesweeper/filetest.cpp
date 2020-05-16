#include <fstream>
#include <iostream>
#include <curses.h>

using namespace std;

int main()
{
    initscr();
    raw();
    noecho();

   fstream file;
   file.open("1.txt",ios::in|ios::out);
   string str;
   while(!file.eof())
   {
       char ch = file.get();
       str.append(1, ch);
   }


   mvprintw(1,1, str.c_str());
   refresh();
   getch();

   file.close();

   return 0;
}
