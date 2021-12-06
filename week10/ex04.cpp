[���α׷� �ҽ�]
#include <string>
#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size); //s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* remove(int s1[], int s2[], int size, int& retSize); //s1���� s2�� �ִ� ���ڸ� ��� ������ ���ο� �迭�� ���� �����Ͽ� ����
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* arr = new int[size]; //�� �迭�� ��ģ size��ŭ ���ο� �迭 ���� ����
	for (int i = 0; i < size/2; i++) {
		arr[i] = s1[i]; //0����size/2���� ù��° �迭 ����
		arr[i + size / 2] = s2[i]; //ù��° �迭 ���� �ε������� �ι�° �迭 ����
	}
	return arr;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j])  //s1�� ���ҿ� s2�� ���Ұ� ������ 
				s1[i] = 9999; //����
		}
		//9999�� ������ ���� : NULL�� ���Ÿ� �ϰ� �Ǹ� ����ڰ� 0�� �Է¹޾��� �� 0�� NULL�� ���ֵǾ� 0�� ���� ���ŵ�.
		//�׷��� ������ ���� 999�� �����ϴ� ����.
		if (s1[i] != 9999) //���ŵ��� ���� ���Ҹ�ŭ
			retSize++; //���� ����
	}
	if (retSize == 0) return NULL; //��� ���ŵż� ���Ұ� ���� ���

	int* arr = new int[retSize]; //������ ���̸�ŭ ���ο� �迭 ���� ����
	int num = 0;
	for (int i = 0; i < size; i++)
		if (s1[i] != 9999) {
			arr[num] = s1[i]; //���ο� �迭�� s1�� ���� �߰�
			num++;
		}
	return arr;
}

int main() {
	int x[5]; //ù��° �迭
	int y[5]; //�ι�° �迭
	int size = 0, retSize = 0;
	int* add;
	int* remove;

	cout << "���� 5���� �Է��϶�. �迭 x�� �����Ѵ� >> ";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "���� 5���� �Է��϶�. �迭 y�� �����Ѵ� >> ";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}

	size = (sizeof(x) + sizeof(y)) / sizeof(int);
	add = ArrayUtility2::concat(x, y, size); //��ģ �迭
	cout << "��ģ ���� �迭�� ����Ѵ�." << endl;
	for (int i = 0; i < size; i++) {
		cout << add[i] << " ";
	}

	size = sizeof(x) / sizeof(int);
	remove = ArrayUtility2::remove(x, y, 5, retSize); //�� �迭
	cout << endl << "�迭 x[]���� y[]�� �� ����� ����Ѵ� ������ " << retSize << endl;
	for (int i = 0; i < retSize; i++) {
		cout << remove[i] << ' ';
	}
}

