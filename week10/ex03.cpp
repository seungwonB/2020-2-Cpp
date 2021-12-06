[���α׷� �ҽ�]
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Random {
public:
	static void rndnum() {
		srand((unsigned)time(0));
	}
	static int nextInt(int min = 0, int max = 32767); //min�� max ������ ���� ���� ����
	static char nextAlphabet(); //�����ϰ� ������ ��ȯ
	static string nextString(int length); //�Ű������� ���޵� ���̸� ���� ������ ���ڿ� ��ȯ
};

int Random::nextInt(int min, int max) {
	int rnd = rand() % (max - min + 1) + min; //min~max������ ���� ����
	return rnd;
}

char Random::nextAlphabet() {
	//65~90(A~Z), 97~122(a~z)
	char ch;
	while (1) {
		int rnd1 = rand() % (122 - 65 + 1) + 65;
		if (rnd1 >= 91 && rnd1 <= 96) //91~96�� �ٸ� �����̱� ������ �װ͵��� �����ֱ� ����
			continue;
		else {
			ch = (char)rnd1; //ch�� ���� ���� ����
			break;
		}
	}
	return ch;
}

string Random::nextString(int length) {
	string str;
	for (int i = 0; i < length; i++) {
		str += nextAlphabet(); //���� ���ڵ��� �Ű������� ���� ���̸�ŭ str�� �����Ͽ� ���ڿ� ����
	}
	return str;
	
}

int main() {
	Random::rndnum();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�." << endl;

	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100) << '\t';
	}
	
	cout << endl << endl << "���ĺ��� �����ϰ� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << '\t';
	}

	cout << endl << endl << "���̰� 5~15�� ������ ���ڿ� 5���� ����մϴ�." << endl;
	for (int i = 0; i < 5; i++) {
		int length = rand() % 11 + 5; //5~15�� ���� ������ ���̷� ����
		cout << Random::nextString(length) << ":" << "(" << length << ")" << endl;
	}
}

