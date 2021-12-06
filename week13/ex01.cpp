[���α׷� �ҽ�]
#include <iostream>
#include <string>
using namespace std;

class AbstractGate {
	
public:
	virtual bool operation(bool x, bool y) = 0; //���� ���� �Լ�
};

class ANDGate : public AbstractGate {
	bool x, y;
public:
	bool operation(bool x, bool y) {
		this->x = x;
		this->y = y;
		if (x == true && y == true) //�� ���� ��� true�� true
			return true;
		else  //�ϳ��� false��
			return false; //false
	}
	void show() {
		cout << "AND : " << boolalpha << x << ", " << boolalpha << y << " => " << operation(x, y) << endl;
	}
};

class ORGate : public AbstractGate {
	bool x, y;
public:
	bool operation(bool x, bool y) {
		this->x = x;
		this->y = y;
		if (x == true || y == true)  //�� �� �� �ϳ��� true��
			return true; //true
		else  //��� false��
			return false; //false
	}
	void show() {
		cout << "OR : " << boolalpha << x << ", " << boolalpha << y << " => " << operation(x,y) << endl;
	}
};

class XORGate : public AbstractGate {
	bool x, y;
public:
	bool operation(bool x, bool y) {
		this->x = x;
		this->y = y;
		if (x != y) // �� ���� �ٸ��� true
			return true;
		else  // ������
			return false; //false
	}
	void show() {
		cout << "XOR : " << boolalpha << x << ", " << boolalpha << y << " => " << operation(x, y) << endl;
	}
};

class Manage:public AbstractGate {
public:
	static void go();
};

void Manage::go() {
	int num;
	int a, b;
	bool loop = true;
	ORGate orgate;
	ANDGate andgate;
	XORGate xorgate;
	while (loop) {
		cout << "���� ������ �����ϼ���. 1 : and, 2 : or, 3 : xor, 4 : stop >> ";
		cin >> num;
		switch (num) {
		case 1:
			cout << "����Ʈ �Է� �� >> ";
			cin >> a >> b;
			andgate.operation(a, b);
			andgate.show();
			break;
		case 2:
			cout << "����Ʈ �Է� �� >> ";
			cin >> a >> b;
			orgate.operation(a, b);
			orgate.show();
			break;
		case 3:
			cout << "����Ʈ �Է� �� >> ";
			cin >> a >> b;
			xorgate.operation(a, b);
			xorgate.show();
			break;
		case 4:
			cout << "����Ǿ����ϴ�." << endl;
			loop = false;
			break;
		default:
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			continue;
		}
	}
}

int main() { 
	Manage::go();
}

