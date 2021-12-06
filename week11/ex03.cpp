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
		cout << "radius = " << radius << " �� ��" << endl;
	}
	friend Circle operator++(Circle& c);
	friend Circle operator++(Circle& op, int x);
	friend Circle operator+(int n, Circle op2);
};

Circle operator++(Circle& c) {
	c.radius++; //c�� radius 1����
	return c;
}

Circle operator++(Circle& op, int x) {
	Circle tmp = op; //�����ϱ� ���� op ���� ����
	op.radius++;
	return tmp;
}

Circle operator+(int n, Circle op2) {
	Circle circle;
	circle.radius = n + op2.radius; //���� n + ��ü op2�� radius ���ϱ�
	return circle; //�ӽ� ��ü ����
}

int main() {
	Circle a(5), b(4);
	++a; //a=6
	b = a++; //a=7 b=6
	cout << "Circle ��ü : ++a" << endl;
	a.show(); //a�� 7���
	cout << "Circle ��ü : b=a++" << endl;
	b.show(); //b�� 6���
	b = 1 + a; //b=8
	cout << "Circle ��ü : b=1+a" << endl;
	b.show(); //b�� 8���
}

