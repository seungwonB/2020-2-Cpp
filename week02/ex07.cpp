#include <iostream>
#include <string>
using namespace std;

//auto형은 함수 원형 제시 불가능, 매개 변수 타입도 사용 불가능 but 반환 타입, 변수 선언은 가능(단, 변수선언은 초기화 필수)
auto sum(int a, int b) {
	auto res = 0;
	for (auto k = a; k <= b; k++) {
		res += k;
	}
	return res;
}

int main() {
	auto n = 0;
	cout << "끝 수를 입력하세요 >> ";
	cin >> n;

	if (n <= 0) {
		cout << "양수를 입력하세요! \n";
	}
	else {
		cout << "1에서 " <<  n << "까지의 합은 " << sum(1,n) << " 입니다\n";
	}
	return 0;
}

