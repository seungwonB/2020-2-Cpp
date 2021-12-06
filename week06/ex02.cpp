#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:
	Player() { name = ""; }
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

class Game {
	Player* p;
	string first, second;
public:
	Game() {
		first = "tree"; //tree로 초기화
	}
	~Game() {
		delete[] p; //메모리 반환
	}
	void word();
};

void Game::word() {
	int count;
	string str;
	
	cout << "끝말잇기 게임을 시작합니다." << endl;
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	cin >> count;
	p = new Player[count]; //입력받은 숫자만큼 배열 생성

	for (int i = 0; i < count; i++) {
		cout << "참가자의 이름을 입력하세요.(빈칸없이) >> ";
		cin >> str;
		p[i].setName(str); //생성된 배열에 입력받은 값 저장
	}

	cout << "시작하는 단어는 tree입니다. " << endl;
	int index = 0;
	
	while (true) {
		cout << p[index].getName() << " >> "; //순서대로 입력받은 이름 값 출력
		cin >> second; //사용자들이 입력하는 단어
		int size = first.size(); //첫번째 단어의 사이즈 = 4(tree)
		if (first.at(size - 1) == second.at(0)) { //at은 index값의 문자를 선택하는 것이므로 1을 빼준다. 앞의 단어 마지막 글자와 그 다음 단어 첫번째 글자를 비교한다.
			first = second; // 같으면 후에 입력된 단어를 다음 입력될 단어와 비교하기 위해 다시 first에 저장한다.
		}
		else { //같지 않으면 종료
			cout << endl << p[index].getName() << "가(이) 졌습니다.!"; 
			break;
		}
		++index;
		if (index >= count) index = 0; //index값이 count(입력받은 선수 수)값보다 커지면 안된다.
	}
}
int main() {
	Game g;
	g.word();
	return 0;
}

