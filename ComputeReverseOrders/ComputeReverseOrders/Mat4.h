#pragma once

using namespace std;

class matrix {
private:
	int root[4][4];
public:
	matrix() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				root[i][j] = 0;
			}
		}
	}

	int get(int i, int j) {
		return root[i][j];
	}

	void set(int i, int j, int value) {
		root[i][j] = value;
	}
		

	void print() {											//输出用函数
		cout << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << root[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	matrix operator+(matrix& b) {
		matrix result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.set(i, j,  this->get(i, j)+ b.get(i, j));
			}
		}
		return result;
	}

	matrix operator-(matrix& b) {
		matrix result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.set(i, j, this->get(i, j) - b.get(i, j));
			}
		}
		return result;
	}

	matrix operator*(matrix& b) {
		matrix result;
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int q = 0; q < 4; q++) {
					sum += this->get(i, q) * b.get(q, j);
				}
				result.set(i, j, sum);
				sum = 0;
			}
		}
		return result;
	}
};
//测试代码写在main函数里了，源文件白建了。。。