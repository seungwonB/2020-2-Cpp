#include <iostream>
#include <string>
using namespace std;

class Account {
	int money;
public:
	Account(int money); //매개변수로 받은 값으로 잔액 초기화
	int getMoney(); //잔액 반환
	void setMoney(int money); //매개변수로 받은 값 만큼 잔액 증가
	void show(); //잔액 출력
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
	cout << "잔액이 " << money << " 원 있습니다." << endl;
}

void increaseBy(Account& a, int money) {
	a.setMoney(a.getMoney() + money); //객체 a의 money와 입력받은 money를 합한 값을 객체 a에 저장 
}

int main(){
	Account account(50000);
	int money;
	cout << "입금 전 ";
	account.show();
	cout << "입금액 : ";
	cin >> money;
	increaseBy(account, money); 
	cout << "입금 후 ";
	account.show();
	return 0;
}


