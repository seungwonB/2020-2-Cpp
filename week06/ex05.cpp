#include <iostream>
#include <string>
using namespace std;

class Container { // 통 하나를 나타내는 클래스
	int size; // 현재 저장 량, 최대 저장 가능량은 10
public:
	Container() { size = 10; }
	void fill(int n); // n 만큼 채우기
	bool consume(int n); // n 만큼 소모하기
	int getSize(); // 현재 크기 리턴
};

void Container::fill(int n) {
	size = n; // 10만큼 채우기
}

bool Container::consume(int n) {
	if (size < n) {
		cout << "원료가 부족합니다. " << endl;
		return false;  //현재 양이 소비될 양보다 적으면 false값 반환 (물이 1있는데 물이 2인 음료를 구매할 경우)
	}
	if (size > 0) {
		size -= n; // n만큼 소모
		return true;
	}
	else {
		return false; // 0이하면 false
	}
}

int Container::getSize() {
	return size;
}

class CoffeeVMachine { // 커피 자판기를 표현하는 클래스
	Container tong[3]; // tong[0]는 커피, tong[1]은 물, tong[2]는 설탕통을 나타냄
	void fill(); // 3개의 통을 모두 10으로 채움
	void selectEspresso(); // 에스프레소를 선택한 경우, 커피 1, 물 1 소모
	void selectAmericano(); // 아메리카노를 선택한 경우,  커피 1, 물 2 소모
	void selectSugarCoffee(); // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모
	void show(); // 현재 커피, 물, 설탕의 잔량 출력
	bool checkInputError(int menu); // 오류 처리를 위해 추가한 멤버 함수
public:
	void run(); // 커피 자판기 작동
};

void CoffeeVMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10); //커피 물 설탕통 모두 10으로 채워주기
	}
}

void CoffeeVMachine::selectEspresso() {
	if (tong[0].consume(1) && tong[1].consume(1)) 
		cout << "에스프레소 드세요" << endl;
	else {
		cout << "에스프레소를 못 만듭니다." << endl;
		return;
	}
}

void CoffeeVMachine::selectAmericano() {
	if (tong[0].consume(1) && tong[1].consume(2))
		cout << "아메리카노 드세요" << endl;
	else {
		cout << "아메리카노를 못 만듭니다." << endl;
		return;
	}
}

void CoffeeVMachine::selectSugarCoffee() {
	if (tong[0].consume(1) && tong[1].consume(2) && tong[2].consume(1))
		cout << "설탕커피 드세요" << endl;
	else {
		cout << "설탕커피를 못 만듭니다." << endl;
		return;
	}
}

void CoffeeVMachine::show() {
	cout << "커피 : " << tong[0].getSize();
	cout << ", 물 : " << tong[1].getSize();
	cout << ", 설탕 : " << tong[2].getSize() << endl;
}

bool CoffeeVMachine::checkInputError(int menu) {
	if(menu >= 0 || menu <= 5) //메뉴는 1,2,3,4,5,0이다.
		return true;
	else { //그 외는 잘못 입력한 값이다.
		return false;
	}
		
}

void CoffeeVMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	int menu;
	
	do {
		cout << "메뉴를 눌러주세요 (1 : 에스프레소, 2 : 아메리카노, 3 : 설탕커피, 4 : 잔량보기, 5 : 채우기, 0 : 종료) >> ";
		cin >> menu;
		switch (menu) {
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		case 0:
			cout << "종료합니다. " << endl;
			return;
		default:
			cout << "다시 입력하세요 " << endl;
			break;
		}
		
	} while (checkInputError(menu));
}

int main() {
	CoffeeVMachine cvm;
	cvm.run();

	return 0;
}


