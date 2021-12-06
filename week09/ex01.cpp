#include <iostream>
#include <string>
using namespace std;

class Big {
public:
	string big(string a, string b); //���ڿ� �� ū �� ��
	int big(char a[], int size); //���� �迭 �� ū �� ��
};

string Big::big(string a, string b) {
	return a > b ? a : b; //a�� b�� ū ���� ����
}

int Big::big(char a[], int size) {
	int index = 0;
	for (int i = 1; i < size; i++) {
		if (a[index] < a[i]) {
			index = i; 
		}
	}
	return index; //�迭���� ū ���� ������ index�� ����
}

int main() {
	Big b;
	string result = "";
	char ch[] = { 'd','a','e','A','p','x','q' };
	int size = sizeof(ch) / sizeof(char); //�迭�� ������
	cout << "big(list, array) : " << b.big("list", "array") << endl; //'l'�� 'a'���� ���� ŭ
	int index = b.big(ch, size);
	
	cout << "big(ch, " << size << ") : " << ch[index];
	/*
	result = "big(ch, " + to_string(size);
	result += ") : ";
	cout << result << ch[index] << endl;
	*/
	return 0;
}

