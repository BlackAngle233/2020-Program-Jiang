#include <iostream>
#include "MyString.h"

using namespace std;

int main()
{
    MyString str("Hello");
    MyString str1(" My Friend!");
    str = str + str1;
    MyString str3(MyString("My name is ") + MyString("KYLN."));
    cout << str << endl
         << str3 << endl;
    return 0;
}