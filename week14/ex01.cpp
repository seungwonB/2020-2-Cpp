[프로그램 소스]
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
		cout << year << "년도, " << title << ", " << author << endl;
	}
};

class BookManager {
	vector<Book*> v; //Book객체를 저장하기 위한 vector 객체 생성
	void searchByAuthor(); //저자로 검색
	void searchByYear(); //연도로 검색
	void bookIn(); //벡터에 Book 정보 저장
	void finish();
public:
	void run();
};

void BookManager::bookIn() {
	int year;
	string title, author;
	Book* ip;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 종료합니다." << endl;
	while (1) {
		cout << "년도>>";
		cin >> year;
		cin.ignore(1, '\n'); 
		if (year == -1)
			break;
		cout << "책이름>>";
		getline(cin, title);
		cout << "저자>>";
		cin >> author;
		ip = new Book(title, author, year); //입력 받은 정보를 Book의 주소에 저장
		v.push_back(ip); //주소를 vector에 삽입
	}
	cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;
}

void BookManager::searchByAuthor() {
	string name;
	cout << "검색하고자 하는 저자이름을 입력하세요>>";
	cin >> name;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->getAuthor() == name)
			v[i]->show();
	}
}

void BookManager::searchByYear() {
	int year;
	cout << "검색하고자 하는 년도를 입력하세요>>";
	cin >> year;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->getYear() == year)
			v[i]->show();
	}
}


void BookManager::finish() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->getAuthor() << " 메모리 반납 완료" << endl;
		delete v[i];
	}
}

void BookManager::run() {
	bookIn(); //입고
	searchByAuthor(); //저자로 검색
	searchByYear(); //년도로 검색
	finish(); //메모리반납
}

int main(){
	BookManager man;
	man.run();

	return 0;
}

