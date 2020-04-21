#pragma once
#include "pch.h"

struct Mat4
{
	int data[4][4];
};

void ShowMat4(Mat4 );

Mat4 AddMat4(Mat4 , Mat4 );

Mat4 SubMat4(Mat4 , Mat4 );

Mat4 MulMat4(Mat4 , Mat4 );
