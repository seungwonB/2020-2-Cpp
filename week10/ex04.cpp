[프로그램 소스]
#include <string>
#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size); //s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize); //s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* arr = new int[size]; //두 배열을 합친 size만큼 새로운 배열 동적 생성
	for (int i = 0; i < size/2; i++) {
		arr[i] = s1[i]; //0부터size/2까지 첫번째 배열 저장
		arr[i + size / 2] = s2[i]; //첫번째 배열 다음 인덱스부터 두번째 배열 저장
	}
	return arr;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j])  //s1의 원소와 s2의 원소가 같으면 
				s1[i] = 9999; //제거
		}
		//9999로 제거한 이유 : NULL로 제거를 하게 되면 사용자가 0을 입력받았을 시 0은 NULL로 간주되어 0이 같이 제거됨.
		//그래서 임의의 변수 999로 제거하는 형태.
		if (s1[i] != 9999) //제거되지 않은 원소만큼
			retSize++; //길이 증가
	}
	if (retSize == 0) return NULL; //모두 제거돼서 원소가 없는 경우

	int* arr = new int[retSize]; //증가된 길이만큼 새로운 배열 동적 생성
	int num = 0;
	for (int i = 0; i < size; i++)
		if (s1[i] != 9999) {
			arr[num] = s1[i]; //새로운 배열에 s1의 원소 추가
			num++;
		}
	return arr;
}

int main() {
	int x[5]; //첫번째 배열
	int y[5]; //두번째 배열
	int size = 0, retSize = 0;
	int* add;
	int* remove;

	cout << "정수 5개를 입력하라. 배열 x에 삽입한다 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	cout << "정수 5개를 입력하라. 배열 y에 삽입한다 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> y[i];
	}

	size = (sizeof(x) + sizeof(y)) / sizeof(int);
	add = ArrayUtility2::concat(x, y, size); //합친 배열
	cout << "합친 정수 배열을 출력한다." << endl;
	for (int i = 0; i < size; i++) {
		cout << add[i] << " ";
	}

	size = sizeof(x) / sizeof(int);
	remove = ArrayUtility2::remove(x, y, 5, retSize); //뺀 배열
	cout << endl << "배열 x[]에서 y[]를 뺀 결과를 출력한다 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) {
		cout << remove[i] << ' ';
	}
}

