#include <iostream>
#include <string>
using namespace std;

class Person {
	string name; //가족구성원들의 이름 (ex 컴공, 간호, 심리)
public:
	Person() { name = ""; } // 공백 생성자
	Person(string name) { this->name = name; } // 이름을 매개변수로 갖는 생성자
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Family { // Family가 Person에 상속되어 있는 개념이다.
	Person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수
	string group; // 가족명 (ex 한림)
public:
	Family(string group, int size); // size 개수만큼 Person 배열 동적 생성
	void show(); // 모든 가족 구성원 출력
	~Family(); // 소멸자
	void setName(int index, string name); 
};

Family::Family(string group, int size) {
	p = new Person[size]; // 입력받은 size만큼 person배열 생성
	this->size = size;
	this->group = group;
}

void Family::show() {
	cout << group << " 가족은 다음과 같이 " << size << " 명 입니다. " << endl;
	for (int i = 0; i < size; i++) {
		cout << (i + 1) << ") " << p[i].getName() << endl; // person배열에 있는 이름 출력
	}
}
void Family::setName(int index, string name) {
	p[index].setName(name); // 입력받는 이름을 index에 저장
	//(p + index)->setName(name); 위와 동일
}

Family::~Family() { delete[] p; }

int main(){
	Family* simpson;
	int size = 0; //가족 수
	string group,name; //가족명, 가족구성원이름
	cout << "가족 수를 입력하세요 >> ";
	cin >> size;
	cout << "가족명을 입력하세요 >> ";
	cin >> group;
	simpson = new Family(group, size); //group의 가족명을 가지고 size명인 simpson가족 생성 
	
	for (int i = 0; i < size; i++) {
		cout << (i+1) << ". 이름을 입력하세요. >> ";
		cin >> name;
		simpson->setName(i,name); //simpson가족 구성원들의 이름 설정
	}

	simpson->show();
	delete simpson;
	return 0;
 
}



