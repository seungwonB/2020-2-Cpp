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
	static int answer; //����� �� ��, ������ �ʱ�ȭ
	static int top; //����� �� ���� �������� �ְ�
	static int bottom; //����� �� ���� �������� ������
	static void init(); //������ �����Ͽ� answer������ �ʱ�ȭ
	static void msg(); //top�� bottm ���
public:
	static void run(); //���� ����
	static bool check(int answer); //top�� bottom�� �����ϰ�, ������ ���߸� true �ƴϸ� false
};

bool Person::go() {
	int number;
	cout << name + ">> ";
	cin >> number;
	return UpAndDownGame::check(number);
}
//static ��� ������ �޸� �Ҵ��� ���� ����Ʈ ����
int UpAndDownGame::answer = 0;
int UpAndDownGame::top = 100;
int UpAndDownGame::bottom = 1;

void UpAndDownGame::init() { //answer ���� ���� �ʱ�ȭ
	srand((unsigned)time(0)); //������ ������ �ٸ� �������� �߻���Ű�� ���� seed ����
	answer = rand() % 100 + 1; //1���� 100������ ������ ���� �߻�
}

void UpAndDownGame::msg() {
	cout << "���� " << bottom << "�� " << top << "���̿� �ֽ��ϴ�." << endl;
}

void UpAndDownGame::run() { //������ ���鼭 ������ ����
	Person* players[2];
	string name;

	cout << "Up & Down ������ �����մϴ�." << endl;
	for (int i = 0; i < 2; i++) {
		cout << "�̸��� �Է��ϼ��� >> ";
		cin >> name;
		players[i] = new Person(name);
	}

	init(); //���� �õ� 

	int i = 0;
	while (true) {
		msg();
		if (players[i]->go()) { 
			cout << players[i]->getName() << "��(��) �̰���ϴ�!!" << endl;
			break;
		}
		i++; //���� ��� ������ ���� ���� ����
		i = i % 2; //2���̱⿡ i%2
	}
}

bool UpAndDownGame::check(int a) {
	if (a < bottom || a > top) return false;
	if (answer == a) //����� �Է¹��� ���� ������ true
		return true;
	if (a > answer) //�Է¹��� ���� ���亸�� ũ��
		top = a; //top�� a��
	else //������
		bottom = a; //bottom�� a��
	return false;
}

int main() {
	UpAndDownGame::run();
}

