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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
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
	price = price + op; //기존 price에 매개변수로 받은 op를 더함
	return *this; //합한 결과 리턴
}

Book& Book::operator-= (int op) {
	price = price - op; //기존 price에 매개변수로 받은 op를 뺌
	return *this; //뺀 결과 리턴
}

bool Book::operator==(int price) {
	if (this->price == price)  //기존 price와 매개변수로 받은 price가 같은지 비교하여
		return true; //같으면 true
	else  
		return false; //다르면 false
}

bool Book::operator==(string title) {
	if (this->title == title) //기존 title와 매개변수로 받은 price가 같은지 비교하여
		return true; //같으면 true
	else
		return false; //다르면 false
}

bool Book::operator==(Book op) {
	if (title == op.title && price == op.price && pages == op.pages) //객체가 같은지 비교
		return true;
	else
		return false;
}

int main() {
	Book a("청춘", 20000, 300);
	Book b("미래", 30000, 500);
	a += 500; //책 a의 가격 500원 증가
	b -= 500; //책 b의 가격 500원 감소
	a.show();
	b.show();

	Book c("명품 C++", 30000, 500);
	Book d("고품 C++", 30000, 500);
	if (c == 30000) //price 비교
		cout << "정가 30000원" << endl; 
	if (c == "명품 C++") //title 비교
		cout << "명품 C++입니다." << endl;
	if (c == d) //모두 비교
		cout << "두 책이 같은 책입니다. " << endl;
	else
		cout << "두 책이 다른 책입니다." << endl;
}

