[프로그램 소스]
#include <iostream>
#include <string>
using namespace std;

class AbstractGate {
	
public:
	virtual bool operation(bool x, bool y) = 0; //순수 가상 함수
};

class ANDGate : public AbstractGate {
	bool x, y;
public:
	bool operation(bool x, bool y) {
		this->x = x;
		this->y = y;
		if (x == true && y == true) //두 값이 모두 true면 true
			return true;
		else  //하나라도 false면
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
		if (x == true || y == true)  //두 값 중 하나라도 true면
			return true; //true
		else  //모두 false면
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
		if (x != y) // 두 값이 다르면 true
			return true;
		else  // 같으면
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
		cout << "연산 종류를 선택하세요. 1 : and, 2 : or, 3 : xor, 4 : stop >> ";
		cin >> num;
		switch (num) {
		case 1:
			cout << "게이트 입력 값 >> ";
			cin >> a >> b;
			andgate.operation(a, b);
			andgate.show();
			break;
		case 2:
			cout << "게이트 입력 값 >> ";
			cin >> a >> b;
			orgate.operation(a, b);
			orgate.show();
			break;
		case 3:
			cout << "게이트 입력 값 >> ";
			cin >> a >> b;
			xorgate.operation(a, b);
			xorgate.show();
			break;
		case 4:
			cout << "종료되었습니다." << endl;
			loop = false;
			break;
		default:
			cout << "잘못입력하였습니다." << endl;
			continue;
		}
	}
}

int main() { 
	Manage::go();
}

