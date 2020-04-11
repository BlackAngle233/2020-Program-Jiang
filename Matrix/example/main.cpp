//
//  main.cpp
//  example
//
//  Created by 章大卫 on 2020/4/11.
//  Copyright © 2020 章大卫. All rights reserved.
//

#include <iostream>
#include "mat4.hpp"
using namespace std;
int num1[4][4]=
{
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4}
};
int num2[4][4]=
{
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4},
    {1,2,3,4}
};
int num3[4][4]={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int main(int argc, const char * argv[]) {
    plusNums(num1, num2);
    subNums(num1, num2);
    multiplicationNums(num1,num2,num3);
}

