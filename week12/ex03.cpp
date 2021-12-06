#include <iostream>
#include <string>
using namespace std;

class BasePrinter {
	string model; //모델
	string manufacturer; //제조사
	int printedCount = 0; //인쇄 매수
	int availableCount; //인쇄 종이 잔량
	int add;
public:
	BasePrinter(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	string getModel() {
		return model;
	}
	string getManu() {
		return manufacturer;
	}
	int getAvail() {
		return availableCount;
	}
	int getPrinted() {
		return printedCount;
	}
	void print(int pages) {
		while (1) {
			if (availableCount >= pages) { //입력받은 pages보다 인쇄 종이가 많아 출력이 가능한 경우
				availableCount -= pages; //입력한 만큼 인쇄 종이 감소
				printedCount += pages; //입력한 만큼 인쇄 매수 증가
				break;
			}
			else { //입력받은 pages보다 인쇄 종이가 적어 출력이 불가능한 경우
				cout << "용지가 부족하여 프린트 할 수 없습니다." << endl;
				cout << "용지를 추가해 주세요.";
				cin >> add;
				cout << "용지를 " << add << "추가 합니다." << endl;
				availableCount += add; //추가한 add만큼 인쇄 종이에 추가
				if (availableCount >= pages) {
					availableCount -= pages;
					printedCount += pages;
					break;
				}
				else //추가했는데도 부족한 경우 다시 추가
					continue;
			}
		}
		
	}
};	

class InkJetPrinter:public BasePrinter {
	int availableInk; //잉크 잔량
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) : BasePrinter(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void printInkJet(int pages); //pages 수만큼 용지 사용, 잉크잔량은 pages 수만큼 감소
	void showStateInkJet(); //현재 상태 출력
	int getInk() {
		return availableInk;
	}
};

void InkJetPrinter::printInkJet(int pages) {
	print(pages);
	if (availableInk > pages) {
		availableInk -= pages; //입력한 pages만큼 ink감소
		cout << "프린트하였습니다." << endl;
	}
	if (pages == 0) //0을 입력한 경우 현재 프린트 상태만 출력
		return;
}

void InkJetPrinter::showStateInkJet() {
	cout << getModel() << ", " << getManu() << ", 인쇄 매수 " << getPrinted() << "장 , 남은 종이 " << getAvail() << "장, 남은 잉크 " << getInk() << endl;
}

class LaserPrinter :public BasePrinter {
	int availableToner; //토너 잔량
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : BasePrinter(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void printLaser(int pages); //pages 수만큼 용지 사용, 토너 잔량은 -1감소
	void showStateLaser(); // 현재 상태 출력
	int getToner() {
		return availableToner;
	}
};

void LaserPrinter::printLaser(int pages){
	print(pages);
	if (availableToner > pages) {
		availableToner -= 1; //토너 잔량을 사용할 때마다 -1감소
		cout << "프린트하였습니다." << endl;
	}
	if (pages == 0) //0을 입력한 경우 현재 프린트 상태만 출력
		return;
}

void LaserPrinter::showStateLaser() {
	cout << getModel() << ", " << getManu() << ", 인쇄 매수 " << getPrinted() << "장 , 남은 종이 " << getAvail() << "장, 남은 토너 " << getToner() << endl;
}

int main() {
	int select, num = 0;
	char a;
	InkJetPrinter* ink = new InkJetPrinter("Officeject V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 6, 10);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯 : ";
	ink->showStateInkJet();
	cout << "레이저 : ";
	laser->showStateLaser();

	while (1) {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		cin >> select >> num;
		if (select == 1) {
			ink->printInkJet(num);
			ink->showStateInkJet();
		}
		else if (select == 2) {
			laser->printLaser(num);
			laser->showStateLaser();
		}
		else {
			cout << "다시 입력하시오." << endl;
			continue;
		}
		cout << "계속 프린트 하시겠습니까?(y/n)";
		cin >> a;
		if (a == 'n') {
			cout << "프린트 사용이 종료되었습니다." << endl;
			break;
		}
	}
}

