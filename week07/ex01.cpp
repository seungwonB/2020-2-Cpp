#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {
	int res = 0; //index저장을 위한 변수
	for (int i = 0; i < strlen(a); i++) { //a배열의 길이만큼
		if (a[i] == c) { //a[index] 와 문자 c 의 값이 같으면 true
			success = true;
			res = i; //그때의 index 를 저장
			break;
		}
		else
			success = false;
	}
	return a[res];
}

int main(){
	char ch[] = "C++ programming"; //초기 설정 문자열
	bool b = false; 
	char& loc = find(ch, 'a', b); //문자 'a'가 있는 공간

	cout << "변경 전 문자열 = " << ch << endl;

	if (b==false) {
		cout << "해당 문자를 발견할 수 없습니다." << endl;
	}
	else {
		loc = 'A'; //문자 'a'를 'A'로 변경
		cout << "변경 후 문자열 = " << ch << endl;
	}
	return 0;
}

/*
int i=0;
while(a[i]) {
	if(a[i] == c) {
		succes = true;
		return a[i];
	}
	i++;

}
success = false;
return a[0];
*/

