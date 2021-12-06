[���α׷� �ҽ�]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Book {
	string title;
	string author;
	int year;
public:
	Book() {}
	Book(string title, string author, int year) {
		this->title = title;
		this->author = author;
		this->year = year;
	}
	string getAuthor() { return author; }
	int getYear() { return year; }
	void show() {
		cout << year << "�⵵, " << title << ", " << author << endl;
	}
};

class BookManager {
	vector<Book*> v; //Book��ü�� �����ϱ� ���� vector ��ü ����
	void searchByAuthor(); //���ڷ� �˻�
	void searchByYear(); //������ �˻�
	void bookIn(); //���Ϳ� Book ���� ����
	void finish();
public:
	void run();
};

void BookManager::bookIn() {
	int year;
	string title, author;
	Book* ip;
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �����մϴ�." << endl;
	while (1) {
		cout << "�⵵>>";
		cin >> year;
		cin.ignore(1, '\n'); 
		if (year == -1)
			break;
		cout << "å�̸�>>";
		getline(cin, title);
		cout << "����>>";
		cin >> author;
		ip = new Book(title, author, year); //�Է� ���� ������ Book�� �ּҿ� ����
		v.push_back(ip); //�ּҸ� vector�� ����
	}
	cout << "�� �԰�� å�� " << v.size() << "���Դϴ�." << endl;
}

void BookManager::searchByAuthor() {
	string name;
	cout << "�˻��ϰ��� �ϴ� �����̸��� �Է��ϼ���>>";
	cin >> name;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->getAuthor() == name)
			v[i]->show();
	}
}

void BookManager::searchByYear() {
	int year;
	cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
	cin >> year;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->getYear() == year)
			v[i]->show();
	}
}


void BookManager::finish() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->getAuthor() << " �޸� �ݳ� �Ϸ�" << endl;
		delete v[i];
	}
}

void BookManager::run() {
	bookIn(); //�԰�
	searchByAuthor(); //���ڷ� �˻�
	searchByYear(); //�⵵�� �˻�
	finish(); //�޸𸮹ݳ�
}

int main(){
	BookManager man;
	man.run();

	return 0;
}

