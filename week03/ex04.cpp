#include <iostream>
#include <string>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar; // ��ü Ŀ��, ����, ���� ��
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso(); // Ŀ�� 1, �� 1 �Һ�	
	void drinkAmericano(); // Ŀ�� 1, �� 2 �Һ�
	void drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
	void fill(); // Ŀ�� 10, �� 10, ���� 10���� ä���
	void show(); // �ܷ� ���
};

CoffeeMachine::CoffeeMachine(int c,int w,int s) {
	coffee = c;
	water = w;
	sugar = s;
}

void CoffeeMachine::drinkEspresso() {
if(coffee < 1 || water < 1) return;
	coffee -= 1;
	water -= 1;
}

void CoffeeMachine::drinkAmericano() {
if(coffee < 1 || water < 2) return;
	coffee -= 1;
	water -= 2;
}

void CoffeeMachine::drinkSugarCoffee() {
if(coffee < 1 || water < 1 || sugar < 1) return;
	coffee -= 1;
	water -= 2;
	sugar -= 1;
}

void CoffeeMachine::fill() {
	coffee = 10;
	water = 10;
	sugar = 10;
}

void CoffeeMachine::show() {
	cout << "Ŀ�� �ӽ� ����, Ŀ��:" << coffee << "\t��:" << water << "\t����:" << sugar << endl;
}

int main() {
	CoffeeMachine java(5, 10, 6); // Ŀ�Ƿ�:5, ����:10, ����:6���� �ʱ�ȭ
	java.drinkEspresso(); // Ŀ�� 1, �� 1 �Һ�	
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.drinkAmericano(); // Ŀ�� 1, �� 2 �Һ�
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���
	java.fill(); // Ŀ�� 10, �� 10, ���� 10���� ä���
	java.show(); // ���� Ŀ�� �ӽ��� ���� ���

	return 0;
}

