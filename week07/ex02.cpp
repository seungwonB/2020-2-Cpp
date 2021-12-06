#include <iostream>
#include <string>
using namespace std;

class Account {
	int money;
public:
	Account(int money); //�Ű������� ���� ������ �ܾ� �ʱ�ȭ
	int getMoney(); //�ܾ� ��ȯ
	void setMoney(int money); //�Ű������� ���� �� ��ŭ �ܾ� ����
	void show(); //�ܾ� ���
};

Account::Account(int money) {
	this->money = money;
}

void Account::setMoney(int money) {
	this->money = money;
}

int Account::getMoney() {
	return money;
}

void Account::show() {
	cout << "�ܾ��� " << money << " �� �ֽ��ϴ�." << endl;
}

void increaseBy(Account& a, int money) {
	a.setMoney(a.getMoney() + money); //��ü a�� money�� �Է¹��� money�� ���� ���� ��ü a�� ���� 
}

int main(){
	Account account(50000);
	int money;
	cout << "�Ա� �� ";
	account.show();
	cout << "�Աݾ� : ";
	cin >> money;
	increaseBy(account, money); 
	cout << "�Ա� �� ";
	account.show();
	return 0;
}


