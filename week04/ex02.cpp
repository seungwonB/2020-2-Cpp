#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cout << "�Է��� �Ǽ��� ������? ";
	cin >> n;
	
	double *p = new double[n]; //�Է� �޴� �Ǽ��� ���� �ϴ� ������ �迭

	if (!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cout << i + 1 << "��° �Ǽ�: ";
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

