#include <string>
#include <iostream>
using namespace std;

class MyIntStack {
	char* p; //���� �޸𸮷� ����� ������
	int size; //������ �ִ� ũ��
	int tos; //������ ž�� ����Ű�� �ε���
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(char n); //n�� ���ÿ� Ǫ��, ������ �� �� ������ false�� �ƴϸ� true ����
	bool pop(char& n); //������ ž�� �ִ� ���� n�� ��, ���� ������ ��������� false�� �ƴϸ� true ����
	void show();
};

MyIntStack::MyIntStack() {
	size = 1;
	tos = -1;
	p = new char[size];
}

MyIntStack::MyIntStack(int size) {
	tos = -1;
	this->size = size;
	p = new char[size];
}


MyIntStack::MyIntStack(const MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new char[s.size];
	for (int i = 0; i < size; i++) {
		this->p[i] = s.p[i]; // ���� ��ü�� �޸� ����
	}
}

MyIntStack::~MyIntStack() {
	delete[] p; //���� �޸� ��ȯ
}

bool MyIntStack::push(char n) {
	if (tos == (size - 1))  //������ �����̸� false
		return false;
	else {
		p[++tos] = n; //�迭�� 1���� �� n�� Ǫ��
		return true; //���ÿ� �߰��� �� ������ true
	}
}

bool MyIntStack::pop(char& n) {
	if (size < 1) return false; //������ �����̸� false
	else {
		n = p[tos]; //������ ž�� �ִ� �� 
		--tos; //���� 1����
		return true;
	}
}

void MyIntStack::show() {
	for (int i = tos; i >= 0; i--) { //������ �������� ���
		cout << p[i] << " "; 
	}
}

int main() {
	MyIntStack a(20);
	a.push('a');
	a.push('f');
	a.push('k');
	cout << "== ����(a) ==" << endl;
	a.show();
	MyIntStack b = a;
	cout << endl << "== ����(b) ==" << endl;
	b.push('q');
	b.show();
	char n;
	a.pop(n);
	cout << endl << "���� a���� ���� �� : " << n << endl;
	b.pop(n);
	cout << "���� b���� ���� �� : " << n << endl;

}

