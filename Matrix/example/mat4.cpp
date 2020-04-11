//
//  mat4.cpp
//  example
//
//  Created by 章大卫 on 2020/4/11.
//  Copyright © 2020 章大卫. All rights reserved.
//
#include <iostream>
#include "mat4.hpp"
using namespace std;
void print(int n[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0; j<4; j++) {
            cout<<n[i][j]<<",";
        }
        cout<<endl;
    }
}
void plusNums(int n[4][4],int m[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0; j<4; j++)
        {
            n[i][j]+=m[i][j];
        }
    }
    print(n);
}
void subNums(int n[4][4],int m[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0; j<4; j++)
        {
            n[i][j]-=m[i][j];
        }
    }
    print(n);
}
void multiplicationNums(int n[4][4],int m[4][4],int num3[4][4]){

    for(int i=0;i<4;i++)
    {
        for (int j=0; j<4; j++)
        {
           for (int k=0; k<4; k++)
           {
               num3[i][j]+=n[j][k]*m[k][j];
           }
        }
    }
    print(num3);
}
