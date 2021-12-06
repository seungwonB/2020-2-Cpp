[프로그램 소스]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

template <class T1, class T2, class T3>
bool search(T1 x, T2 arr[], T3 size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == x)
			return true; //같으면 true
	}
	return false; //다르면 false
}

int main(){
	int x[] = { 1, 10, 100, 5, 4 };
	double y[] = { 1.3, 10.9, 8.3, 100.2 };
	char z[] = { 'c','g','w','x','z','q' };
	if (search(100, x, 5))
		cout << "100이 배열 x에 포함되어 있다." << endl;
	else
		cout << "100이 배열 x에 포함되어 있지 않다." << endl;

	if (search(1.4, x, 4))
		cout << "1.4가 배열 y에 포함되어 있다." << endl;
	else
		cout << "1.4가 배열 y에 포함되어 있지 않다." << endl;

	if (search('g', z, 6))
		cout << "g가 배열 z에 포함되어 있다." << endl;
	else
		cout << "g가 배열 z에 포함되어 있지 않다." << endl;
}


