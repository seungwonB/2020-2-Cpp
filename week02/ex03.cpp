#include <iostream>
#include <string>

using namespace std;

void ShowMenu(void);       // �޴� ���
void MakeAccount(void);    // ���°���
void ShowAllAccInfo(void);     // ��ü ���� ��ȸ

enum { MAKE = 1, INQUIRE, EXIT };

struct Account
{
	int accID;      // ���¹�ȣ
	int balance;    // ��    ��
	string cusName;   // ���̸�

	void show() {
		cout << "���¹�ȣ: " << accID;
		cout<< "\t��  ��: " << cusName;
		cout << "\t��  ��: " << balance << endl;
	}
};

//C++ ������ ������ typedef ���� ���� �±׸� ��� ����ü ���� ����
Account accArr[100];   // Account ������ ���� �迭
int accNum = 0;        // ����� Account ��

int main(){
	int choice;

	while (1)	{
		ShowMenu();
		cout << "����: ";
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
			cout << "�ش� �޴��� �����ϴ�" << endl;
		}
	}
	return 0;
}

void ShowMenu(){
	cout << "-----Menu------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �������� ��ü ���" << endl;
	cout << "3. ���α׷� ����" << endl;
}

void MakeAccount(){
	int id;
	string name;
	int balance;

	cout << "[���°���]" << endl;
	cout << "���¹�ȣ: ";
	cin >> id;
	cin.ignore(1, '\n');
	cout << "��  ��: ";	
	getline(cin, name);
	cout << "�Աݾ�: ";	
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

