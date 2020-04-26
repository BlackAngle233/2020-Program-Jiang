struct Mat
{
	int m[4][4];
};

void printMartix4x4(const Mat& m1);

void inputMartix4x4(Mat& m1);

Mat add(const Mat& m1,const Mat& m2);

Mat minus(const Mat& m1, const Mat& m2);

Mat multiple(const Mat& m1, const Mat& m2);