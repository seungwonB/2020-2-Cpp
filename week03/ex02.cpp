#include <iostream>
#include <string>
using namespace std;

class Member {
private:
	string id;
	string pw;
public:
	Member(); //�����ڿ� ���� ���ǰ� �ϳ��� �ִٸ� ����Ʈ �����ڸ� ����
	Member(string id, string pw);
	Member(string id);
	bool isCheck(); // id, pw ��
	void disPlay(); //���
};

Member::Member() : Member("null", "null"){ } //���� ������(Ÿ�� �����ڸ� ȣ���ϴ� ������)
Member::Member(string i, string p) : id(i), pw(p) { } //Ÿ�� ������
Member::Member(string i) : id(i) { 
} 	cout << "�Ű������� �ϳ��� Member������ �Դϴ�. " << endl;
	cout << "pw �Է� >> ";
	cin >> pw;


bool Member::isCheck() { 
	if (id == pw)
		return false;
	else
		return true;
	//���̵�� ��й�ȣ�� ������ ��� �Ұ�
}

void Member::disPlay() {
	cout << "id >> " + id << endl;
	cout << "pw >> " + pw << endl << endl;
}

int main() {
	Member mem; //����Ʈ ������ ȣ���ؼ� ��ü ����
	Member mem1("C++", "C++");
	Member mem2("Java1");
	mem.disPlay();
	mem1.disPlay();
	if (mem1.isCheck()) {
		cout << "��� ������ pw �Դϴ�. " << endl;
	}
	else {
		cout << "id�� ������ pw�� ����� �� �����ϴ�. " << endl << endl;
	}
	mem2.disPlay();

	return 0;
}

