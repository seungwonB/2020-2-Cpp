#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {
	int res = 0; //index������ ���� ����
	for (int i = 0; i < strlen(a); i++) { //a�迭�� ���̸�ŭ
		if (a[i] == c) { //a[index] �� ���� c �� ���� ������ true
			success = true;
			res = i; //�׶��� index �� ����
			break;
		}
		else
			success = false;
	}
	return a[res];
}

int main(){
	char ch[] = "C++ programming"; //�ʱ� ���� ���ڿ�
	bool b = false; 
	char& loc = find(ch, 'a', b); //���� 'a'�� �ִ� ����

	cout << "���� �� ���ڿ� = " << ch << endl;

	if (b==false) {
		cout << "�ش� ���ڸ� �߰��� �� �����ϴ�." << endl;
	}
	else {
		loc = 'A'; //���� 'a'�� 'A'�� ����
		cout << "���� �� ���ڿ� = " << ch << endl;
	}
	return 0;
}

/*
int i=0;
while(a[i]) {
	if(a[i] == c) {
		succes = true;
		return a[i];
	}
	i++;

}
success = false;
return a[0];
*/

