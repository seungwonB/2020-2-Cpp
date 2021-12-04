#include <iostream>
#include <string>

using namespace std;

void ShowMenu(void);       // 메뉴 출력
void MakeAccount(void);    // 계좌개설
void ShowAllAccInfo(void);     // 전체 계좌 조회

enum { MAKE = 1, INQUIRE, EXIT };

struct Account
{
	int accID;      // 계좌번호
	int balance;    // 잔    액
	string cusName;   // 고객이름

	void show() {
		cout << "계좌번호: " << accID;
		cout<< "\t이  름: " << cusName;
		cout << "\t잔  액: " << balance << endl;
	}
};

//C++ 에서는 별도의 typedef 선언 없이 태그를 사용 구조체 선언 가능
Account accArr[100];   // Account 저장을 위한 배열
int accNum = 0;        // 저장된 Account 수

int main(){
	int choice;

	while (1)	{
		ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice){
		case MAKE:
			MakeAccount();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "해당 메뉴가 없습니다" << endl;
		}
	}
	return 0;
}

void ShowMenu(){
	cout << "-----Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 계좌정보 전체 출력" << endl;
	cout << "3. 프로그램 종료" << endl;
}

void MakeAccount(){
	int id;
	string name;
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌번호: ";
	cin >> id;
	cin.ignore(1, '\n');
	cout << "이  름: ";	
	getline(cin, name);
	cout << "입금액: ";	
	cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	accArr[accNum].cusName= name;
	accNum++;
}

void ShowAllAccInfo(){
	for (auto i = 0; i < accNum; i++){
		accArr[i].show();
	}
}

