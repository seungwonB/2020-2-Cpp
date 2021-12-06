#include <iostream>
#include <string>
using namespace std;

class Add {
public:
	int a, b;
	void setValue(int x, int y);
	int calculate();
};

class Minus {
public:
	int a, b;
	void setValue(int x, int y);
	int calculate();
};

class Mod {
public:
	int a , b ;
	void setValue(int x, int y);
	int calculate();
};

class Mul {
public:
	int a  , b ;
	void setValue(int x, int y);
	int calculate();
};

void Add :: setValue(int x, int y) {
	a = x;
	b = y;
}

int Add::calculate() {
	return a + b;
}

void Minus::setValue(int x, int y) {
	a = x;
	b = y;
}

int Minus::calculate() {
	return a - b;
}

void Mod::setValue(int x, int y) {
	a = x;
	b = y;
}

int Mod::calculate() {
	return a % b;
}

void Mul::setValue(int x, int y) {
	a = x;
	b = y;
}

int Mul::calculate() {
	return a * b;
}

int main() {
	Add add;
	Minus min;
	Mod mod;
	Mul mul;
	int num=0;
	int q, w;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	while (1) {
		cout << "1: (+), 2:(*), 3:(%), 4:(-), 5:exit >> ";
		cin >> num;
		if (num == 1) {
			cout << "operand >> ";
			cin >> q >> w;
			add.setValue(q, w);
			cout << "Add : " << add.calculate() << endl;
			++cnt1;
		}
		else if (num == 2) {
			cout << "operand >> ";
			cin >> q >> w;
			mul.setValue(q, w);
			cout << "Mul : " << mul.calculate() << endl;
			++cnt2;
		}
		else if (num == 3) {
			cout << "operand >> ";
			cin >> q >> w;
			mod.setValue(q, w);
			cout << "Mod : " << mod.calculate() << endl;
			++cnt3;
		}
		else if (num == 4) {
			cout << "operand >> ";
			cin >> q >> w;
			min.setValue(q, w);
			cout << "Minus : " << min.calculate() << endl;
			++cnt4;
		}
		else if (num == 5) {
			cout << "Add = " << cnt1 << "번 사용하셨습니다. " << endl;
			cout << "Mul = " << cnt2 << "번 사용하셨습니다. " << endl;
			cout << "Mod = " << cnt3 << "번 사용하셨습니다. " << endl;
			cout << "Minus = " << cnt4 << "번 사용하셨습니다. " << endl;
			cout << "종료되었습니다." << endl;
			break;
		}
		else {
			cout << "잘못입력하였습니다. 다시 입력하세요. " << endl;
			continue;
		}
	}

	return 0;
}

