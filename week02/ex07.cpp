#include <iostream>
#include <string>
using namespace std;

//auto���� �Լ� ���� ���� �Ұ���, �Ű� ���� Ÿ�Ե� ��� �Ұ��� but ��ȯ Ÿ��, ���� ������ ����(��, ���������� �ʱ�ȭ �ʼ�)
auto sum(int a, int b) {
	auto res = 0;
	for (auto k = a; k <= b; k++) {
		res += k;
	}
	return res;
}

int main() {
	auto n = 0;
	cout << "�� ���� �Է��ϼ��� >> ";
	cin >> n;

	if (n <= 0) {
		cout << "����� �Է��ϼ���! \n";
	}
	else {
		cout << "1���� " <<  n << "������ ���� " << sum(1,n) << " �Դϴ�\n";
	}
	return 0;
}

