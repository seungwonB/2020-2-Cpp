#include <iostream>
#include <string>
using namespace std;

//�Էµ� ���ڿ����� Ư�� ������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���. ��, ���ڿ��� string Ŭ������ ����Ͽ� ó��
int main() {
	string name;
	char ch;
	int sum = 0;

	cout << "���ڿ��� �Է��ϼ���: >> ";
	getline(cin,name);
	cout << "ã���� �ϴ� ���ڸ� �Է��ϼ���: >> ";
	cin >> ch;
	
	for (int i = 0; i < name.length(); i++) {
		if (ch == name[i])
			sum++;
	}
	cout << ch << "�� ������ " << sum << "�� �Դϴ�. \n";

}

