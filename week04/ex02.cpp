#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cout << "입력할 실수의 개수는? ";
	cin >> n;
	
	double *p = new double[n]; //입력 받는 실수를 저장 하는 포인터 배열

	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 실수: ";
		cin >> p[i];
	}

	double sum = 0;
	for (auto i = 0; i < n; i++) {
		sum += p[i];
	}
	cout << "sum = " << sum << "\tave = " << sum / n << endl;

	delete[] p;
	return 0;
}

