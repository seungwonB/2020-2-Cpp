#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) {
		this->radius = radius;
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.14 * radius * radius;
	}
};

class NamedCircle :public Circle {
	string name;
public:
	//����Ʈ �Ű�����
	NamedCircle(int radius = 0, string name = "") : Circle(radius) {
		this->name = name;
	}
	void setName(int r, string name) {
		setRadius(r); 
		this->name = name; 
	}
	string getName() {
		return name;
	}
};

int main() {
	int x, max;
	string name;
	NamedCircle pizza[5];
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i < 5; i++) {
		cout << (i + 1) << " >> ";
		cin >> x >> name;
		pizza[i].setName(x, name); //�迭�� �������� �̸� ����
	}
	
	//�ִ� ã��
	max = pizza[0].getArea();
	for (int i = 1; i < 5; i++) {
		if (max < pizza[i].getArea()) {
			max = pizza[i].getArea();
			name = pizza[i].getName();
		}
	}

	cout << "���� ������ ū ���ڴ� " << name << "�Դϴ�." << endl;

}

