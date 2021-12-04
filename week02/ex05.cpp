#include <iostream>
#include <string>
using namespace std;

void ShowMenu(void);
void MakeAccount(void);
void ShowAllAccInfo(void);

enum {
	MAKE = 1, INQUIRE, EXIT
};

struct Account {
	long accID;
	string cusName;
	int balance;

	void show() {
		cout << "계좌번호: " << accID;
		cout << "\t이 름: " << cusName;
		cout << "\t잔 액: " << balance << endl;
	}

	void input() {
		cout << "[계좌개설]" << endl;
		cout << "계좌번호: ";
		cin >> accID;
		cin.ignore(1, '\n');
		cout << "이 름: ";
		getline(cin, cusName);
		cout << "입금액: ";
		cin >> balance;
		cout << endl;
	}
};

Account accArr[100];
int accNum = 0;

int main() {
	int choice;

	while (1) {
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			MakeAccount();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			cout << "프로그램이 종료되었습니다. ";
			return 0;
		default:
			cout << "해당 메뉴가 없습니다. " << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설 " << endl;
	cout << "2. 계좌정보 전체 출력 " << endl;
	cout << "3. 프로그램 종료 " << endl;
}

void MakeAccount() {
	accArr[accNum].input();
	accNum++;
}

void ShowAllAccInfo() {
	for (auto i = 0; i < accNum; i++) {
		accArr[i].show();
	}
	cout << "총 계좌는 " << accNum << "개가 생성되었습니다. \n";
}

