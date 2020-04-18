#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <vector>
#include <iostream>
#include <algorithm>
class Matrix4d
{
public:
    int buffer[4][4];
    Matrix4d()
    {
        for(int i = 0 ; i < 4;i++)
        {
            std::fill(buffer[i],buffer[i]+4,0);
        }
    }
    Matrix4d(int (&arr)[4][4])
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                buffer[i][j] = arr[i][j];
            }
        }
    }

    Matrix4d operator+(Matrix4d& b)
    {
        Matrix4d answer;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4;j++)
            {
                answer.buffer[i][j] = this -> buffer[i][j] + b.buffer[i][j];
            }
        }
        return answer;
    }
    Matrix4d operator-(Matrix4d& b)
    {
        Matrix4d answer;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4;j++)
            {
                answer.buffer[i][j] = this -> buffer[i][j] - b.buffer[i][j];
            }
        }
        return answer;
    }

    Matrix4d operator*(Matrix4d& b)
    {
        Matrix4d answer;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    answer.buffer[i][j] += this -> buffer[i][k] * b.buffer[k][j];
                }
            }
        }
        return answer;
    }


    void output()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                std::cout << buffer[i][j] << '\t';
                if(j ==3) std::cout << std::endl;
            }
        }
    }
};
#endif

