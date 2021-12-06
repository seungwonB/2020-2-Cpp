#include <iostream>
#include <string>
using namespace std;

class Container { // �� �ϳ��� ��Ÿ���� Ŭ����
	int size; // ���� ���� ��, �ִ� ���� ���ɷ��� 10
public:
	Container() { size = 10; }
	void fill(int n); // n ��ŭ ä���
	bool consume(int n); // n ��ŭ �Ҹ��ϱ�
	int getSize(); // ���� ũ�� ����
};

void Container::fill(int n) {
	size = n; // 10��ŭ ä���
}

bool Container::consume(int n) {
	if (size < n) {
		cout << "���ᰡ �����մϴ�. " << endl;
		return false;  //���� ���� �Һ�� �纸�� ������ false�� ��ȯ (���� 1�ִµ� ���� 2�� ���Ḧ ������ ���)
	}
	if (size > 0) {
		size -= n; // n��ŭ �Ҹ�
		return true;
	}
	else {
		return false; // 0���ϸ� false
	}
}

int Container::getSize() {
	return size;
}

class CoffeeVMachine { // Ŀ�� ���Ǳ⸦ ǥ���ϴ� Ŭ����
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� �������� ��Ÿ��
	void fill(); // 3���� ���� ��� 10���� ä��
	void selectEspresso(); // ���������Ҹ� ������ ���, Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano(); // �Ƹ޸�ī�븦 ������ ���,  Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarCoffee(); // ����Ŀ�Ǹ� ������ ���, Ŀ�� 1, �� 2 �Ҹ�, ���� 1 �Ҹ�
	void show(); // ���� Ŀ��, ��, ������ �ܷ� ���
	bool checkInputError(int menu); // ���� ó���� ���� �߰��� ��� �Լ�
public:
	void run(); // Ŀ�� ���Ǳ� �۵�
};

void CoffeeVMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill(10); //Ŀ�� �� ������ ��� 10���� ä���ֱ�
	}
}

void CoffeeVMachine::selectEspresso() {
	if (tong[0].consume(1) && tong[1].consume(1)) 
		cout << "���������� �弼��" << endl;
	else {
		cout << "���������Ҹ� �� ����ϴ�." << endl;
		return;
	}
}

void CoffeeVMachine::selectAmericano() {
	if (tong[0].consume(1) && tong[1].consume(2))
		cout << "�Ƹ޸�ī�� �弼��" << endl;
	else {
		cout << "�Ƹ޸�ī�븦 �� ����ϴ�." << endl;
		return;
	}
}

void CoffeeVMachine::selectSugarCoffee() {
	if (tong[0].consume(1) && tong[1].consume(2) && tong[2].consume(1))
		cout << "����Ŀ�� �弼��" << endl;
	else {
		cout << "����Ŀ�Ǹ� �� ����ϴ�." << endl;
		return;
	}
}

void CoffeeVMachine::show() {
	cout << "Ŀ�� : " << tong[0].getSize();
	cout << ", �� : " << tong[1].getSize();
	cout << ", ���� : " << tong[2].getSize() << endl;
}

bool CoffeeVMachine::checkInputError(int menu) {
	if(menu >= 0 || menu <= 5) //�޴��� 1,2,3,4,5,0�̴�.
		return true;
	else { //�� �ܴ� �߸� �Է��� ���̴�.
		return false;
	}
		
}

void CoffeeVMachine::run() {
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	int menu;
	
	do {
		cout << "�޴��� �����ּ��� (1 : ����������, 2 : �Ƹ޸�ī��, 3 : ����Ŀ��, 4 : �ܷ�����, 5 : ä���, 0 : ����) >> ";
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
			cout << "�����մϴ�. " << endl;
			return;
		default:
			cout << "�ٽ� �Է��ϼ��� " << endl;
			break;
		}
		
	} while (checkInputError(menu));
}

int main() {
	CoffeeVMachine cvm;
	cvm.run();

	return 0;
}


