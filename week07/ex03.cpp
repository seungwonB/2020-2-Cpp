[프로그램 소스]
#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size; //scores 배열의 크기
	int* scores; // 동적 할당 받을 정수 배열의 주소
public:
	Dept(int size); //매개변수로 받은 배열 크기만큼 scores 배열 생성
	Dept(Dept& dept); //복사 생성자
	~Dept(); //소멸자
	int getSize(); //배열 크기 반환
	void read(); //size 만큼 기보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index); //index의 학생의 성적이 60보다 크면 true 리턴
};

Dept::Dept(int size) {
	this->size = size;
	scores = new int[size];
}

Dept::Dept(Dept& dept) {
	this->size = dept.size;
	scores = new int[size];
	
	for (int i = 0; i < dept.size; i++) {
		this->scores[i] = dept.scores[i];	//scores배열에 복사
	}
}

Dept::~Dept() {
	delete[] scores;
}

int Dept::getSize() {
	return size;
}

void Dept::read() {
	int num;
	for (int i = 0; i < size; i++) {
		cout << "[" << (i + 1) << "] ";
		cin >> num;
		scores[i] = num;
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60)
		return true;
	else
		return false;
}

int countPass(Dept& com) {
	int cnt = 0;
	for (int i = 0; i < com.getSize(); i++) {
		if (com.isOver60(i))
			cnt++;
	}
	return cnt;
}

int main(){
	Dept* com;
	int cnt;
	cout << "학생 수를 입력하세요 >> ";
	cin >> cnt;
	com = new Dept(cnt);
	com->read();
	int n = countPass(*com);
	cout << "60점 이상은 " << n << "명" << endl;
	delete com;
}



