#include <iostream>
#include <string>	
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	~Circle() {
		cout << "������ " << radius << " ��ü �Ҹ�~~" << endl;
	}
	void setRadius(int r) {
		radius = r;
	}
	double getArea();
	int getRadius() const{
		return radius;
	}
};

double Circle::getArea() {
	return 3.14 * radius * radius;
}

class CircleManage {
	Circle* p;
	int size;
public:
	CircleManage(); //sizeũ���� �迭�� ���� ����. ����ڷκ��� �Է� �Ϸ�
	~CircleManage();  // �������� �Ҵ���� �޸� �ݳ�
	void CircleWrite(); //��ü �迭�� ������ 100~200������ Circle ��ü�˻��Ͽ� ���
};

CircleManage::CircleManage() {
	cout << "�����ϰ��� �ϴ� ���� ���� >> ";
	cin >> size;
	p = new Circle[size]; //�Է¹��� ��ŭ �����ϴ� ������ �迭

	int radius;
	for (int i = 0; i < size; i++) {
		cout << "��" << i + 1 << ": ";
		cin >> radius;
		p[i].setRadius(radius); //������ �迭�� ����
	}
}

void CircleManage::CircleWrite() {
	int count = 0;
	Circle *pArray = p;
	for (int i = 0; i < size; i++) {
		cout << "������ = " << pArray->getRadius() << "\t���� = " << pArray->getArea() << endl;
		if (pArray->getArea() >= 100 && pArray->getArea() <= 200)
			count++;
		pArray++;
	}
	cout << endl << "������ 100���� 200 ������ ���� ������ " << count << endl << endl;
}

CircleManage::~CircleManage() {
	delete[] p;
}

int main() {
	CircleManage cm;
	cm.CircleWrite();
	return 0;
}

