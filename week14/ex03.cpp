[프로그램 소스]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Nation {
	string capital;
	string nation;
public:
	Nation() {}
	void set(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getNation() { return nation; }
	string getCapiatal() { return capital; }
	void add();
};

void Nation::add() {
	vector<Nation> v;
	Nation n;
	int x; //메뉴 정하는 변수
	string a1, a2; //추가되는 나라와 수도 변수
	string quiz; //퀴즈 맞추는 변수
	bool loop = true; //반복문 탈출을 위한 변수
	int cnt = 0; //정답을 맞힌 개수
	string vnation[] = { "대한민국", "호주", "미국" , "핀란드", "노르웨이", "뉴질랜드", "스웨덴", "프랑스", "포르투갈" };
	string vcapital[] = { "서울", "캔버라", "워싱턴", "헬싱키", "오슬로", "웰링턴", "스톡홀름", "파리", "리스본" };

	for (int i = 0; i < 9; i++) {
		v.push_back(n); //벡터에 삽입
		v[i].set(vnation[i], vcapital[i]); //배열에 있는 값들을 모두 저장
	}

	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;

	while (1) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
		cin >> x;
		
		if (x == 1) { //정보입력
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요.(no no 이면 입력끝)" << endl;
			int i = v.size();
			while (1) {
				cout << (i + 1) << ">>"; 
				cin >> a1 >> a2; 
				i++;
				if (a1 == "no" && a2 == "no") //no no 입력시 추가 종료
					break;
				 
				for (int j = 0; j < v.size(); j++) { 
					if (v[j].getNation() == a1) { //이미 있는 나라를 입력할시
						cout << "이미 존재하는 나라입니다. " << endl;
						loop = false;
						break; 
					}
				}

				if (loop) { //입력받은 값들을 모두 저장
					v.push_back(n);
					v[i-1].set(a1, a2);
				}
			}
		}
		else if (x == 2) { //퀴즈
			for (int i = 0; i < v.size(); i++) { //벡터의 크기만큼 반복
				cout << v[i].getNation() << "의 수도는? ";
				cin >> quiz;
				if (quiz == "exit")
					break;
				if (quiz == v[i].getCapiatal()) { //정답을 맞힐 때
					cnt++;
					cout << "Correct !!" << endl;
				}
				else //틀릴 때
					cout << "NO !!" << endl;
			}
			cout << "총 맞힌 개수는 " << cnt << "개 입니다." << endl; //맞힌 개수를 추가해봄.
		}else if (x == 3) { //종료
			cout << "종료되었습니다." << endl;
			break;
		}
		else { //오류처리
			cout << "잘못입력하였습니다." << endl;
			continue;
		}
		
	}
}

int main(){
	Nation nation;
	nation.add();
}



