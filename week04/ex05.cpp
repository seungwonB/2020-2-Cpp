#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; //���� ������ ��
	string name; //���� �̸�
public:
	void setCircle(string n, int r); //�̸��� ������ ����
	double getArea(); //���� ��ȯ
	string getName(); //�̸� ��ȯ
};

class CircleManage {
	Circle* p; //Circle �迭�� ���� ������
	int size; //�迭�� ũ��
public:
	CircleManage(int s); //size ũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	~CircleManage();
	void searchByName(); //����ڷκ��� ���� �̸��� �Է� �޾� ���� ���
	void searchByArea(); //����ڷκ��� ������ �Է� �޾� �������� ū ���� �̸� ���
};

void Circle::setCircle(string n, int r) {
	name = n;
	radius = r;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

string Circle::getName() {
	return name;
}

CircleManage::CircleManage(int s) {
	size = s;
	p = new Circle[size]; //�迭 �Ҵ�
	string name;
	int radius;

	for (int i = 0; i < size; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius); //�Է¹��� ������ �迭�� ����
	}
}

CircleManage::~CircleManage() {
	delete[] p; //�迭 �޸� ��ȯ
}

void CircleManage::searchByName(){
	string search;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> search;

	for (int i = 0; i < size; i++) {
		if (search == p[i].getName()) {//�˻��� �̸��� �迭�� ����� �̸��� ������ ���� ���
			cout << "=== " << search << "�� ������ " << p[i].getArea() << "�Դϴ�. " << "===" << endl;
			return;
		}
	}
	cout << search << "�� ã�� �� �����ϴ�. " << endl;
}

void CircleManage::searchByArea() {
	int number;
	int cnt = 0;
	cout << "�ּ� ������ ������ �Է��ϼ��� ";
	cin >> number;
	cout << number << "���� ū ���� �˻��մϴ�. " << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > number) {
			cout << "===" << p[i].getName() << "�� ������ " << p[i].getArea() << "�Դϴ�. " << "===" << endl;
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "ã���� ���� �����ϴ�." << endl;
	}
}
int main() {
	int n;
	cout << "���� ���� >>";
	cin >> n;
	CircleManage cm(n);
	cm.searchByName();
	cm.searchByArea();
	return 0;
}

