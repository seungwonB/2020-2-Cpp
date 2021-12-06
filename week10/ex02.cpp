#include <iostream>
#include <string>
using namespace std;

int add(int a[], int size,int b[] = nullptr) { //null�� ��� 0�� ���� �ǹ̶� ����Ű�� �ִ� �� ���ٴ� nullptr�̿�
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += a[i]; // �迭 a�� ��� ���� ��
	}

	if (b == nullptr)
		return sum; // �迭 b�� ������ a�� �ո� ����

	for (int i = 0; i < size; i++) {
		sum += b[i]; // �迭 b�� ��� ���� ��
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

