#include <string>
#include <iostream>
using namespace std;

class Person {
	string name;
	string tel;

public:
	Person(string n, string t) : name(n), tel(t) { }
	string getName() { return name;  }
	string getTel() { return tel;  }
	void disPlay() {
		cout << "name = " << name << "\ttel = " << tel << endl;
	}
};

int main() {
	Person* p[3];

	string name, tel;
	int size = sizeof(p) / sizeof(p[0]);

	for (int i = 0; i < size; i++) {
		cout << ">> name, tel: ";
		cin >> name;
		cin >> tel;
		p[i] = new Person(name, tel); //배열에 하나씩 넣어주는 작업
	}

	for (int i = 0; i < size; i++) {
		p[i]->disPlay();
	}

	for (int i = 0; i < size; i++) {
		delete p[i]; //배열의 메모리 반환
	}
	
	return 0;
}

