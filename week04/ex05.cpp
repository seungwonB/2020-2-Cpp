#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius; //원의 반지름 값
	string name; //원의 이름
public:
	void setCircle(string n, int r); //이름과 반지름 설정
	double getArea(); //넓이 반환
	string getName(); //이름 반환
};

class CircleManage {
	Circle* p; //Circle 배열에 대한 포인터
	int size; //배열의 크기
public:
	CircleManage(int s); //size 크기의 배열을 동적 생성. 사용자로부터 입력 완료
	~CircleManage();
	void searchByName(); //사용자로부터 원의 이름을 입력 받아 면적 출력
	void searchByArea(); //사용자로부터 면적을 입력 받아 면적보다 큰 원의 이름 출력
};

void Circle::setCircle(string n, int r) {
	name = n;
	radius = r;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

string Circle::getName() {
	return name;
}

CircleManage::CircleManage(int s) {
	size = s;
	p = new Circle[size]; //배열 할당
	string name;
	int radius;

	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius); //입력받은 값들을 배열에 저장
	}
}

CircleManage::~CircleManage() {
	delete[] p; //배열 메모리 반환
}

void CircleManage::searchByName(){
	string search;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> search;

	for (int i = 0; i < size; i++) {
		if (search == p[i].getName()) {//검색한 이름과 배열에 저장된 이름이 같으면 면적 출력
			cout << "=== " << search << "의 면적은 " << p[i].getArea() << "입니다. " << "===" << endl;
			return;
		}
	}
	cout << search << "는 찾을 수 없습니다. " << endl;
}

void CircleManage::searchByArea() {
	int number;
	int cnt = 0;
	cout << "최소 면적을 정수로 입력하세요 ";
	cin >> number;
	cout << number << "보다 큰 원을 검색합니다. " << endl;

	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > number) {
			cout << "===" << p[i].getName() << "의 면적은 " << p[i].getArea() << "입니다. " << "===" << endl;
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "찾으신 원은 없습니다." << endl;
	}
}
int main() {
	int n;
	cout << "원의 개수 >>";
	cin >> n;
	CircleManage cm(n);
	cm.searchByName();
	cm.searchByArea();
	return 0;
}

