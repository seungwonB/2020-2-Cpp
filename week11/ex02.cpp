#include <string>
#include <iostream>
using namespace std;

class Matrix {
	int ar[4];
public:
	Matrix() {
		for (int i = 0; i < 4; i++) {
			ar[i] = 0;
		}
	}
	Matrix(int a1, int a2, int b1, int b2) {
		ar[0] = a1;
		ar[1] = a2;
		ar[2] = b1;
		ar[3] = b2;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++) {
			cout << ar[i] << ' ';
		}
		cout << "}" << endl;
	}
	friend Matrix operator+(Matrix op1, Matrix op2);
	friend Matrix& operator+=(Matrix& a, Matrix b);
	friend Matrix& operator>>(Matrix m, int x[]);
	friend Matrix& operator<<(Matrix m2, int y[]);
};

Matrix operator+(Matrix op1, Matrix op2) {
	Matrix m;
	for (int i = 0; i < 4; i++) {
		m.ar[i] = op1.ar[i] + op2.ar[i]; //각 배열의 원소 더하기
	}
	return m;
}

Matrix& operator+=(Matrix& a, Matrix b) {
	Matrix tmp;
	for (int i = 0; i < 4; i++) {
		tmp.ar[i] = a.ar[i] += b.ar[i]; //a에 b를 더함
	}
	return tmp;
}

Matrix& operator>>(Matrix m, int x[]) {
	for (int i = 0; i < 4; i++) {
		x[i] = m.ar[i]; //배열 x에 m의 원소 복사
	}
	return m;
}

Matrix& operator<<(Matrix m2, int y[]) {
	for (int i = 0; i < 4; i++) {
		m2.ar[i] = y[i]; //m2배열에 y의 원소 복사
	}
	return m2;
}

int main() {
	Matrix a(1, 2, 3, 4);
	Matrix b(2, 3, 4, 5), c;
	c = a + b;
	a += b;

	a.show();
	b.show();
	c.show();

	int x[4], y[4] = { 5,6,7,8 };
	a >> x; //a의 각 원소르 배열 x에 복사
	b << y; //배열 y의 원소 값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;
	b.show();
}

