#include <string>
#include <iostream>
using namespace std;

class MyIntStack {
	char* p; //스택 메모리로 사용할 포인터
	int size; //스택의 최대 크기
	int tos; //스택의 탑을 가리키는 인덱스
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(char n); //n을 스택에 푸시, 스택이 꽉 차 있으면 false를 아니면 true 리턴
	bool pop(char& n); //스택의 탑에 있는 값을 n에 팝, 만일 스택이 비어있으면 false를 아니면 true 리턴
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
		this->p[i] = s.p[i]; // 원복 객체의 메모리 복사
	}
}

MyIntStack::~MyIntStack() {
	delete[] p; //동적 메모리 반환
}

bool MyIntStack::push(char n) {
	if (tos == (size - 1))  //스택이 만원이면 false
		return false;
	else {
		p[++tos] = n; //배열을 1증가 후 n을 푸쉬
		return true; //스택에 추가할 수 있으면 true
	}
}

bool MyIntStack::pop(char& n) {
	if (size < 1) return false; //스택이 공백이면 false
	else {
		n = p[tos]; //스택의 탑에 있는 값 
		--tos; //스택 1감소
		return true;
	}
}

void MyIntStack::show() {
	for (int i = tos; i >= 0; i--) { //스택의 에서부터 출력
		cout << p[i] << " "; 
	}
}

int main() {
	MyIntStack a(20);
	a.push('a');
	a.push('f');
	a.push('k');
	cout << "== 스택(a) ==" << endl;
	a.show();
	MyIntStack b = a;
	cout << endl << "== 스택(b) ==" << endl;
	b.push('q');
	b.show();
	char n;
	a.pop(n);
	cout << endl << "스택 a에서 팝한 값 : " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 : " << n << endl;

}

