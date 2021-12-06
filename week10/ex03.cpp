[프로그램 소스]
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
	static int nextInt(int min = 0, int max = 32767); //min과 max 사이의 랜덤 정수 리턴
	static char nextAlphabet(); //랜덤하게 영문자 반환
	static string nextString(int length); //매개변수로 전달된 길이를 갖는 임의의 문자열 반환
};

int Random::nextInt(int min, int max) {
	int rnd = rand() % (max - min + 1) + min; //min~max까지의 랜덤 정수
	return rnd;
}

char Random::nextAlphabet() {
	//65~90(A~Z), 97~122(a~z)
	char ch;
	while (1) {
		int rnd1 = rand() % (122 - 65 + 1) + 65;
		if (rnd1 >= 91 && rnd1 <= 96) //91~96은 다른 문자이기 때문에 그것들을 피해주기 위함
			continue;
		else {
			ch = (char)rnd1; //ch에 랜덤 문자 저장
			break;
		}
	}
	return ch;
}

string Random::nextString(int length) {
	string str;
	for (int i = 0; i < length; i++) {
		str += nextAlphabet(); //랜덤 문자들을 매개변수로 받은 길이만큼 str에 저장하여 문자열 생성
	}
	return str;
	
}

int main() {
	Random::rndnum();
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;

	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100) << '\t';
	}
	
	cout << endl << endl << "알파벳을 랜덤하게 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() << '\t';
	}

	cout << endl << endl << "길이가 5~15인 랜덤한 문자열 5개를 출력합니다." << endl;
	for (int i = 0; i < 5; i++) {
		int length = rand() % 11 + 5; //5~15인 랜덤 정수를 길이로 저장
		cout << Random::nextString(length) << ":" << "(" << length << ")" << endl;
	}
}

