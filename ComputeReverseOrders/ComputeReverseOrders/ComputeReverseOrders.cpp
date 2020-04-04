//
//  main.cpp
//  test
//
//  Created by 章大卫 on 2020/4/4.
//  Copyright © 2020 章大卫. All rights reserved.
//
using namespace std;

#include <iostream>
void printPairs(int num[], int len)
{
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            cout<< "("<<num[i]<<","<<num[j]<<")"<<endl;
        }
    }
}

int getRevseOrders(int num[], int len){
    int a=0;
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len; j++) {
            if(i<j&&num[i]>num[j]){
                a++;
            };
        }
    }
    cout<< "有:"<<a<<"个"<<endl;
    return 0;
}
int main(int argc, const char * argv[]) {
    int num1[] = { 1, 3 , 4 , 7,  2 };
    int num2[] = {9, 8, 7, 6, 5};
    cout<<"num1"<<endl;
    printPairs(num1,5);
    getRevseOrders(num1, 5);
    cout<<"num2"<<endl;
    printPairs(num2,5);
    getRevseOrders(num2, 5);
}



void test()
{
   // int num1[] = { 1, 3 , 4 , 7,  2 };
    //int num2[] = {9, 8, 7, 6, 5};
    // task
    // 1. print out all pairs
    // 2 . compute reverse orders
}