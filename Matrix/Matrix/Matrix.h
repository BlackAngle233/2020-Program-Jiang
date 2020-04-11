#include <iostream>
#pragma once
using namespace std;

class Matrix{
    private:
     int n ;
     int nums[10][10];
     
    public:
     Matrix(){
         n =0;
     }

     void printNums(){
     for(int i =0;i<n;i++){
        for(int j =0 ;j<n;j++)
            cout<<nums[i][j]<<'\t';
        cout<<endl;
        }
     }

     void setNums(){
         cout<<"Input size:";
         cin>>n;
         cout<<"Input nums:"<<endl;
         for(int i=0;i<n;i++)
            for(int j =0;j<n;j++)
                cin>>nums[i][j];
     }

     Matrix operator+(const Matrix &a){
         Matrix ans;
         if(a.n!=n){cout<<"error!"<<endl;
         return ans;
         }
         ans.n=n;
         for(int i = 0;i<n;i++)
             for(int j=0;j<n;j++)
                ans.nums[i][j]=nums[i][j]+a.nums[i][j];
         return ans;
     }

     Matrix operator-(const Matrix&a){
         Matrix ans;
         if(a.n!=n){cout<<"error!"<<endl;
         return ans;
         }
         ans.n=n;
         for(int i = 0;i<n;i++)
             for(int j=0;j<n;j++)
                ans.nums[i][j]=nums[i][j]-a.nums[i][j];
         return ans;
     }

     Matrix operator*(const Matrix&a){
         Matrix ans;
         if(a.n!=n){cout<<"error!"<<endl;
         return ans;
         }
         ans.n=n;
         for(int i = 0;i<n;i++)
            for(int j = 0 ;j<n;j++){
                ans.nums[i][j]=0;
                for(int q=0;q<n;q++)
                    ans.nums[i][j]+=nums[i][q]*a.nums[q][j];
            }
            return ans;
     }
};