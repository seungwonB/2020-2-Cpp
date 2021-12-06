#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	void show() {
		cout << "radius = " << radius << " 인 원" << endl;
	}
	friend Circle operator++(Circle& c);
	friend Circle operator++(Circle& op, int x);
	friend Circle operator+(int n, Circle op2);
};

Circle operator++(Circle& c) {
	c.radius++; //c의 radius 1증가
	return c;
}

Circle operator++(Circle& op, int x) {
	Circle tmp = op; //변경하기 전의 op 상태 저장
	op.radius++;
	return tmp;
}

Circle operator+(int n, Circle op2) {
	Circle circle;
	circle.radius = n + op2.radius; //정수 n + 객체 op2의 radius 더하기
	return circle; //임시 객체 리턴
}

int main() {
	Circle a(5), b(4);
	++a; //a=6
	b = a++; //a=7 b=6
	cout << "Circle 객체 : ++a" << endl;
	a.show(); //a는 7출력
	cout << "Circle 객체 : b=a++" << endl;
	b.show(); //b는 6출력
	b = 1 + a; //b=8
	cout << "Circle 객체 : b=1+a" << endl;
	b.show(); //b는 8출력
}

