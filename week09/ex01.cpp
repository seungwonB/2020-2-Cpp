#include <iostream>
#include <string>
using namespace std;

class Big {
public:
	string big(string a, string b); //문자열 중 큰 값 비교
	int big(char a[], int size); //정수 배열 중 큰 값 비교
};

string Big::big(string a, string b) {
	return a > b ? a : b; //a와 b중 큰 값을 리턴
}

int Big::big(char a[], int size) {
	int index = 0;
	for (int i = 1; i < size; i++) {
		if (a[index] < a[i]) {
			index = i; 
		}
	}
	return index; //배열에서 큰 값을 가지는 index를 리턴
}

int main() {
	Big b;
	string result = "";
	char ch[] = { 'd','a','e','A','p','x','q' };
	int size = sizeof(ch) / sizeof(char); //배열의 사이즈
	cout << "big(list, array) : " << b.big("list", "array") << endl; //'l'이 'a'보다 값이 큼
	int index = b.big(ch, size);
	
	cout << "big(ch, " << size << ") : " << ch[index];
	/*
	result = "big(ch, " + to_string(size);
	result += ") : ";
	cout << result << ch[index] << endl;
	*/
	return 0;
}

