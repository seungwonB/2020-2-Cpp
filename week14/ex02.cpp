[���α׷� �ҽ�]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

template <class T1, class T2, class T3>
bool search(T1 x, T2 arr[], T3 size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == x)
			return true; //������ true
	}
	return false; //�ٸ��� false
}

int main(){
	int x[] = { 1, 10, 100, 5, 4 };
	double y[] = { 1.3, 10.9, 8.3, 100.2 };
	char z[] = { 'c','g','w','x','z','q' };
	if (search(100, x, 5))
		cout << "100�� �迭 x�� ���ԵǾ� �ִ�." << endl;
	else
		cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�." << endl;

	if (search(1.4, x, 4))
		cout << "1.4�� �迭 y�� ���ԵǾ� �ִ�." << endl;
	else
		cout << "1.4�� �迭 y�� ���ԵǾ� ���� �ʴ�." << endl;

	if (search('g', z, 6))
		cout << "g�� �迭 z�� ���ԵǾ� �ִ�." << endl;
	else
		cout << "g�� �迭 z�� ���ԵǾ� ���� �ʴ�." << endl;
}


