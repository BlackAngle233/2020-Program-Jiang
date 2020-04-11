#pragma once

void print(int m[4][4]);
class Matrix4
{
private:
    int m[4][4];

public:
    Matrix4 operator+(Matrix4& rm);
    Matrix4 operator-(Matrix4& rm);
    Matrix4 operator*(Matrix4& rm);
    void set(int m[4][4]);
    void print();
};