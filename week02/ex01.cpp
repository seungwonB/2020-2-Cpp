#include <iostream>
#include <string>       
using namespace std;  

int main() {
	string song("Falling in love with you");  // string song="Falling in love with you";
	string elvis("Elvis Presley");                 
	string singer;                               

	cout<< song + "�� �θ� ������";                   
	cout << "(��Ʈ : ù ���ڴ� " << elvis[0] << ")? ";  

    // getline()�� string Ÿ���� ���ڿ��� �Է� �ޱ� ���� �����Ǵ� ���� �Լ�
   // ������ ���Ե� ���ڿ� �Է� ����
	getline(cin, singer);   // ���ڿ� �Է�, 
	
	if (singer == elvis)     // ���ڿ� ��
		cout << "�¾ҽ��ϴ�."<<endl;
	else
		cout << "Ʋ�Ƚ��ϴ�. " + elvis + "�Դϴ�." << endl;  // +�� ���ڿ� ����

	bool b = true;
	cout << boolalpha << b << endl << endl;  //boolalpha ���� �� ����� Ȯ���� ������
	return 0;
}

