#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->pages = pages;
		this->price = price;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() {
		return title;
	}
	Book& operator+=(int op);
	Book& operator-=(int op);
	bool operator==(int price);
	bool operator==(string title);
	bool operator==(Book op);
};

Book& Book::operator+=(int op) {
	price = price + op; //���� price�� �Ű������� ���� op�� ����
	return *this; //���� ��� ����
}

Book& Book::operator-= (int op) {
	price = price - op; //���� price�� �Ű������� ���� op�� ��
	return *this; //�� ��� ����
}

bool Book::operator==(int price) {
	if (this->price == price)  //���� price�� �Ű������� ���� price�� ������ ���Ͽ�
		return true; //������ true
	else  
		return false; //�ٸ��� false
}

bool Book::operator==(string title) {
	if (this->title == title) //���� title�� �Ű������� ���� price�� ������ ���Ͽ�
		return true; //������ true
	else
		return false; //�ٸ��� false
}

bool Book::operator==(Book op) {
	if (title == op.title && price == op.price && pages == op.pages) //��ü�� ������ ��
		return true;
	else
		return false;
}

int main() {
	Book a("û��", 20000, 300);
	Book b("�̷�", 30000, 500);
	a += 500; //å a�� ���� 500�� ����
	b -= 500; //å b�� ���� 500�� ����
	a.show();
	b.show();

	Book c("��ǰ C++", 30000, 500);
	Book d("��ǰ C++", 30000, 500);
	if (c == 30000) //price ��
		cout << "���� 30000��" << endl; 
	if (c == "��ǰ C++") //title ��
		cout << "��ǰ C++�Դϴ�." << endl;
	if (c == d) //��� ��
		cout << "�� å�� ���� å�Դϴ�. " << endl;
	else
		cout << "�� å�� �ٸ� å�Դϴ�." << endl;
}

