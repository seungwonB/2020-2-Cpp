#include <iostream>
#include <string>
using namespace std;

int main() {
	int sum = 1;
	int sum2 = 0;
	string arr[3] = { "����������", "�Ƹ޸�ī��", "īǪġ��" };
	int arr2[3] = { 2000, 2300, 2500 };
	int num;
	string coffee;
	
	for (int i = 0; i < sizeof(arr2)/sizeof(int); i++) {
 		cout << arr[i] << " " << arr2[i] << "��, ";
	}

	while (1) {
		cout << "\n�ֹ�>> ";
		cin >> coffee >> num;

		for (int i = 0; i < sizeof(arr2) / sizeof(int); i++) {
			if (coffee == arr[i]) {
				sum = num * arr2[i];
			}
		}

		cout << sum << "���Դϴ�. ���ְ� �弼��. ";
		sum2 = sum + sum2;

		if (sum2 >= 20000) {
			cout << endl << "\n���� " << sum2 << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~\n";
			break;
		}
		
	}
	
}

