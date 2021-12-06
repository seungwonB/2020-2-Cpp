#include <iostream>
#include <string>
using namespace std;

int add(int a[], int size,int b[] = nullptr) { //null은 상수 0과 같은 의미라서 가리키고 있는 게 없다는 nullptr이용
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += a[i]; // 배열 a의 모든 값의 합
	}

	if (b == nullptr)
		return sum; // 배열 b가 없으면 a의 합만 리턴

	for (int i = 0; i < size; i++) {
		sum += b[i]; // 배열 b의 모든 값의 합
	}

	return sum;
}

int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5); //15
	int d = add(a, 5, b); //55
	cout << c << endl << d << endl;
}
