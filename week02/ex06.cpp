#include <iostream>
#include <string>
using namespace std;

int main() {
	int sum = 1;
	int sum2 = 0;
	string arr[3] = { "에스프레소", "아메리카노", "카푸치노" };
	int arr2[3] = { 2000, 2300, 2500 };
	int num;
	string coffee;
	
	for (int i = 0; i < sizeof(arr2)/sizeof(int); i++) {
 		cout << arr[i] << " " << arr2[i] << "원, ";
	}

	while (1) {
		cout << "\n주문>> ";
		cin >> coffee >> num;

		for (int i = 0; i < sizeof(arr2) / sizeof(int); i++) {
			if (coffee == arr[i]) {
				sum = num * arr2[i];
			}
		}

		cout << sum << "원입니다. 맛있게 드세요. ";
		sum2 = sum + sum2;

		if (sum2 >= 20000) {
			cout << endl << "\n오늘 " << sum2 << "원을 판매하여 카페를 닫습니다. 내일 봐요~~\n";
			break;
		}
		
	}
	
}

