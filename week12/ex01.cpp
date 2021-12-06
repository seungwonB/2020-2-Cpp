#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point() {
		x = y = 0;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
protected:
	void move_up(int x, int y) { //x,y��ŭ ����
		this->x += x; 
		this->y += y;
	}
	void move_down(int x, int y) { //x,y��ŭ ����
		this->x -= x;
		this->y -= y;
	}
};

class ColorPoint:public Point {
	string color;
public:
	ColorPoint() : Point(0, 0) {
		color = "BLACK";
		cout << "zerPoint ��ü ��� " << endl;
		show();
	}
	ColorPoint(int x, int y) : Point(x, y) { color = "BLUE"; }
	ColorPoint(int x, int y, string color) : Point(x, y) {
		this->color = color;
	}
	void setPoint(int x, int y, char ch); //x��y�� �����ϴ� �Լ�
	void show() {
		cout << color << "������ (" << getX() << ", " << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
	}
};

void ColorPoint::setPoint(int x, int y, char ch) {
	if (ch == '+')
		move_up(x, y);
	else if (ch == '-')
		move_down(x, y);
	else
		return;

	show();
}

int main() {
	ColorPoint zeroPoint; //BLACK�� (0,0) ��ġ�� ��

	ColorPoint blue(5, 5);
	cout << endl << "blue ��ü ���" << endl;
	cout << "���� ��ġ���� x:+10, y:+20 ��ġ�� �̵��մϴ�." << endl;
	blue.setPoint(10, 20, '+'); 

	ColorPoint red(50, 40, "RED");
	cout << endl << "red ��ü ���" << endl;
	red.show();
	cout << "���� ��ġ���� x:-10, y:-20 ��ġ�� �̵��մϴ�." << endl;
	red.setPoint(10, 20, '-');

}

