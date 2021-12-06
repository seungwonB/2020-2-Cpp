#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Person {
	string name;
public:
	Person(string name) { this->name = name; }
	string getName() { return name; }
	bool go();
};

class UpAndDownGame {
	static int answer; //맞춰야 할 답, 난수로 초기화
	static int top; //맞춰야 할 답의 범위에서 최고값
	static int bottom; //맞춰야 할 답의 범위에서 최저값
	static void init(); //난수를 생성하여 answer변수로 초기화
	static void msg(); //top과 bottm 출력
public:
	static void run(); //게임 진행
	static bool check(int answer); //top과 bottom을 조절하고, 정답을 맞추면 true 아니면 false
};

bool Person::go() {
	int number;
	cout << name + ">> ";
	cin >> number;
	return UpAndDownGame::check(number);
}
//static 멤버 변수의 메모리 할당읠 위한 디폴트 선언
int UpAndDownGame::answer = 0;
int UpAndDownGame::top = 100;
int UpAndDownGame::bottom = 1;

void UpAndDownGame::init() { //answer 변수 랜덤 초기화
	srand((unsigned)time(0)); //시작할 때마다 다른 랜덤수를 발생시키기 위한 seed 생성
	answer = rand() % 100 + 1; //1에서 100사이의 랜덤한 정수 발생
}

void UpAndDownGame::msg() {
	cout << "답은 " << bottom << "과 " << top << "사이에 있습니다." << endl;
}

void UpAndDownGame::run() { //루프를 돌면서 게임을 진행
	Person* players[2];
	string name;

	cout << "Up & Down 게임을 시작합니다." << endl;
	for (int i = 0; i < 2; i++) {
		cout << "이름을 입력하세요 >> ";
		cin >> name;
		players[i] = new Person(name);
	}

	init(); //랜덤 시드 

	int i = 0;
	while (true) {
		msg();
		if (players[i]->go()) { 
			cout << players[i]->getName() << "이(가) 이겼습니다!!" << endl;
			break;
		}
		i++; //둘이 계속 번갈아 가며 게임 진행
		i = i % 2; //2명이기에 i%2
	}
}

bool UpAndDownGame::check(int a) {
	if (a < bottom || a > top) return false;
	if (answer == a) //정답과 입력받은 값이 같으면 true
		return true;
	if (a > answer) //입력받은 값이 정답보다 크면
		top = a; //top을 a로
	else //작으면
		bottom = a; //bottom을 a로
	return false;
}

int main() {
	UpAndDownGame::run();
}
