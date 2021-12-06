#include <iostream>
#include <string>
using namespace std;

class BasePrinter {
	string model; //��
	string manufacturer; //������
	int printedCount = 0; //�μ� �ż�
	int availableCount; //�μ� ���� �ܷ�
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
			if (availableCount >= pages) { //�Է¹��� pages���� �μ� ���̰� ���� ����� ������ ���
				availableCount -= pages; //�Է��� ��ŭ �μ� ���� ����
				printedCount += pages; //�Է��� ��ŭ �μ� �ż� ����
				break;
			}
			else { //�Է¹��� pages���� �μ� ���̰� ���� ����� �Ұ����� ���
				cout << "������ �����Ͽ� ����Ʈ �� �� �����ϴ�." << endl;
				cout << "������ �߰��� �ּ���.";
				cin >> add;
				cout << "������ " << add << "�߰� �մϴ�." << endl;
				availableCount += add; //�߰��� add��ŭ �μ� ���̿� �߰�
				if (availableCount >= pages) {
					availableCount -= pages;
					printedCount += pages;
					break;
				}
				else //�߰��ߴµ��� ������ ��� �ٽ� �߰�
					continue;
			}
		}
		
	}
};	

class InkJetPrinter:public BasePrinter {
	int availableInk; //��ũ �ܷ�
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk) : BasePrinter(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	void printInkJet(int pages); //pages ����ŭ ���� ���, ��ũ�ܷ��� pages ����ŭ ����
	void showStateInkJet(); //���� ���� ���
	int getInk() {
		return availableInk;
	}
};

void InkJetPrinter::printInkJet(int pages) {
	print(pages);
	if (availableInk > pages) {
		availableInk -= pages; //�Է��� pages��ŭ ink����
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	if (pages == 0) //0�� �Է��� ��� ���� ����Ʈ ���¸� ���
		return;
}

void InkJetPrinter::showStateInkJet() {
	cout << getModel() << ", " << getManu() << ", �μ� �ż� " << getPrinted() << "�� , ���� ���� " << getAvail() << "��, ���� ��ũ " << getInk() << endl;
}

class LaserPrinter :public BasePrinter {
	int availableToner; //��� �ܷ�
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : BasePrinter(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}
	void printLaser(int pages); //pages ����ŭ ���� ���, ��� �ܷ��� -1����
	void showStateLaser(); // ���� ���� ���
	int getToner() {
		return availableToner;
	}
};

void LaserPrinter::printLaser(int pages){
	print(pages);
	if (availableToner > pages) {
		availableToner -= 1; //��� �ܷ��� ����� ������ -1����
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
	}
	if (pages == 0) //0�� �Է��� ��� ���� ����Ʈ ���¸� ���
		return;
}

void LaserPrinter::showStateLaser() {
	cout << getModel() << ", " << getManu() << ", �μ� �ż� " << getPrinted() << "�� , ���� ���� " << getAvail() << "��, ���� ��� " << getToner() << endl;
}

int main() {
	int select, num = 0;
	char a;
	InkJetPrinter* ink = new InkJetPrinter("Officeject V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 6, 10);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	cout << "��ũ�� : ";
	ink->showStateInkJet();
	cout << "������ : ";
	laser->showStateLaser();

	while (1) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է� >> ";
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
			cout << "�ٽ� �Է��Ͻÿ�." << endl;
			continue;
		}
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)";
		cin >> a;
		if (a == 'n') {
			cout << "����Ʈ ����� ����Ǿ����ϴ�." << endl;
			break;
		}
	}
}

