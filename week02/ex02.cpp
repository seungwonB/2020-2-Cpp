#include <iostream>
using namespace std;
auto IsMaxLevel(int i) {
	if (i >= 100)
		return true;
	else
		return false;
}

void range_for() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int elem : arr)   //�Ǵ� for(auto elem : arr)
		cout << elem << "  ";
}

int main() {
	// auto �� �����ϸ鼭 �ʱ�ȭ �ؾ� ��
	auto name = "range";
	auto number = 20;
	
	cout << "name :" << name << endl;
	cout << "number :" << number << endl<<endl;
	

	auto result = IsMaxLevel(50);
	cout << boolalpha << result << endl<<endl;

	range_for();
	cout << endl<<endl;
	return 0;

