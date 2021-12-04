#include <iostream>
#include <string>       
using namespace std;  

int main() {
	string song("Falling in love with you");  // string song="Falling in love with you";
	string elvis("Elvis Presley");                 
	string singer;                               

	cout<< song + "를 부른 가수는";                   
	cout << "(힌트 : 첫 글자는 " << elvis[0] << ")? ";  

    // getline()은 string 타입의 문자열을 입력 받기 위해 제공되는 전역 함수
   // 공백이 포함된 문자열 입력 가능
	getline(cin, singer);   // 문자열 입력, 
	
	if (singer == elvis)     // 문자열 비교
		cout << "맞았습니다."<<endl;
	else
		cout << "틀렸습니다. " + elvis + "입니다." << endl;  // +로 문자열 연결

	bool b = true;
	cout << boolalpha << b << endl << endl;  //boolalpha 삭제 후 결과도 확인해 보세요
	return 0;
}

