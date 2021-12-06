#include <iostream>
#include <string>
using namespace std;

class Member {
private:
	string id;
	string pw;
public:
	Member(); //생성자에 대한 정의가 하나라도 있다면 디폴트 생성자를 생성
	Member(string id, string pw);
	Member(string id);
	bool isCheck(); // id, pw 비교
	void disPlay(); //출력
};

Member::Member() : Member("null", "null"){ } //위임 생성자(타겟 생성자를 호출하는 생성자)
Member::Member(string i, string p) : id(i), pw(p) { } //타겟 생성자
Member::Member(string i) : id(i) { 
} 	cout << "매개변수가 하나인 Member생성자 입니다. " << endl;
	cout << "pw 입력 >> ";
	cin >> pw;


bool Member::isCheck() { 
	if (id == pw)
		return false;
	else
		return true;
	//아이디랑 비밀번호가 같으면 사용 불가
}

void Member::disPlay() {
	cout << "id >> " + id << endl;
	cout << "pw >> " + pw << endl << endl;
}

int main() {
	Member mem; //디폴트 생성자 호출해서 객체 생성
	Member mem1("C++", "C++");
	Member mem2("Java1");
	mem.disPlay();
	mem1.disPlay();
	if (mem1.isCheck()) {
		cout << "사용 가능한 pw 입니다. " << endl;
	}
	else {
		cout << "id와 동일한 pw는 사용할 수 없습니다. " << endl << endl;
	}
	mem2.disPlay();

	return 0;
}

