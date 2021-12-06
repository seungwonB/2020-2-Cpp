[프로그램 소스]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Who {
public:
	map<string, string> m;
	map<string, string>::iterator it;
	void insert(); //이름과 암호 삽입
	void check(); //검사
	void remove(); //삭제
	void show(); //출력
	void run(); //실행
};

void Who::insert() {
	string id, pass;
	cout << "이름 암호 >> ";
	cin >> id >> pass;
	m.insert(make_pair(id, pass)); //map에 이름과 암호를 한 쌍으로 저장
}

void Who::check() {
	string id, pass;
	cout << "이름 ? ";
	cin >> id;
	cout << "암호 ? ";
	cin >> pass;
	if (pass == m[pass]) //입력한 암호와 저장되어있는 암호가 같으면
		cout << "통과!!" << endl;
	else
		cout << "실패!!" << endl;
}

void Who::remove() {
	string id;
	cout << "이름 ? ";
	cin >> id;
	bool forloop = true;
	for (it = m.begin(); it != m.end(); it++) {
		if (id == it->first) { //입력한 id와 저장되어 있는 첫번재값이 같으면
			m.erase(it); //그 위치에 있는 값을 삭제
			cout << "성공!!" << endl;
			forloop = false;
			break;
		}
	}
	if (forloop)
		cout << "실패!!" << endl;
}

void Who::show() {
	cout << " ---- map에 저장된 데이터 출력 ---- " << endl;
	for (it = m.begin(); it != m.end(); it++) { //출력
		cout << it->first << " : " << it->second << endl;
	}
}

void Who::run() {
	int menu;

	while (1) {
		cout << "삽입:1 , 검사:2 , 삭제:3 , 전체 데이터 출력:4 , 종료:5 >> ";
		cin >> menu;
		if (menu == 1)
			insert();
		else if (menu == 2)
			check();
		else if (menu == 3)
			remove();
		else if (menu == 4)
			show();
		else if (menu == 5) {
			cout << "종료되었습니다." << endl;
			break;
		}
		else {
			cout << "잘못입력하였습니다." << endl;
			continue;
		}
	}
}

int main(){
	Who who;
	cout << "***** 암호관리 프로그램 WHO를 시작합니다. *****" << endl;
	who.run();
}


