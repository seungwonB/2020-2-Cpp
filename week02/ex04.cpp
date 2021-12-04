#include <iostream>
#include <string>
using namespace std;

//입력된 문자열에서 특정 문자의 개수를 출력하는 프로그램을 작성하세요. 단, 문자열은 string 클래스를 사용하여 처리
int main() {
	string name;
	char ch;
	int sum = 0;

	cout << "문자열을 입력하세요: >> ";
	getline(cin,name);
	cout << "찾고자 하는 문자를 입력하세요: >> ";
	cin >> ch;
	
	for (int i = 0; i < name.length(); i++) {
		if (ch == name[i])
			sum++;
	}
	cout << ch << "의 개수는 " << sum << "개 입니다. \n";

}

