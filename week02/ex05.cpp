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
		cout << "���¹�ȣ: " << accID;
		cout << "\t�� ��: " << cusName;
		cout << "\t�� ��: " << balance << endl;
	}

	void input() {
		cout << "[���°���]" << endl;
		cout << "���¹�ȣ: ";
		cin >> accID;
		cin.ignore(1, '\n');
		cout << "�� ��: ";
		getline(cin, cusName);
		cout << "�Աݾ�: ";
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
		cout << "����: ";
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
			cout << "���α׷��� ����Ǿ����ϴ�. ";
			return 0;
		default:
			cout << "�ش� �޴��� �����ϴ�. " << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°��� " << endl;
	cout << "2. �������� ��ü ��� " << endl;
	cout << "3. ���α׷� ���� " << endl;
}

void MakeAccount() {
	accArr[accNum].input();
	accNum++;
}

void ShowAllAccInfo() {
	for (auto i = 0; i < accNum; i++) {
		accArr[i].show();
	}
	cout << "�� ���´� " << accNum << "���� �����Ǿ����ϴ�. \n";
}

