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

	for (int elem : arr)   //또는 for(auto elem : arr)
		cout << elem << "  ";
}

int main() {
	// auto 로 선언하면서 초기화 해야 함
	auto name = "range";
	auto number = 20;
	
	cout << "name :" << name << endl;
	cout << "number :" << number << endl<<endl;
	

	auto result = IsMaxLevel(50);
	cout << boolalpha << result << endl<<endl;

	range_for();
	cout << endl<<endl;
	return 0;

