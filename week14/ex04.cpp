[���α׷� �ҽ�]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Who {
public:
	map<string, string> m;
	map<string, string>::iterator it;
	void insert(); //�̸��� ��ȣ ����
	void check(); //�˻�
	void remove(); //����
	void show(); //���
	void run(); //����
};

void Who::insert() {
	string id, pass;
	cout << "�̸� ��ȣ >> ";
	cin >> id >> pass;
	m.insert(make_pair(id, pass)); //map�� �̸��� ��ȣ�� �� ������ ����
}

void Who::check() {
	string id, pass;
	cout << "�̸� ? ";
	cin >> id;
	cout << "��ȣ ? ";
	cin >> pass;
	if (pass == m[pass]) //�Է��� ��ȣ�� ����Ǿ��ִ� ��ȣ�� ������
		cout << "���!!" << endl;
	else
		cout << "����!!" << endl;
}

void Who::remove() {
	string id;
	cout << "�̸� ? ";
	cin >> id;
	bool forloop = true;
	for (it = m.begin(); it != m.end(); it++) {
		if (id == it->first) { //�Է��� id�� ����Ǿ� �ִ� ù���簪�� ������
			m.erase(it); //�� ��ġ�� �ִ� ���� ����
			cout << "����!!" << endl;
			forloop = false;
			break;
		}
	}
	if (forloop)
		cout << "����!!" << endl;
}

void Who::show() {
	cout << " ---- map�� ����� ������ ��� ---- " << endl;
	for (it = m.begin(); it != m.end(); it++) { //���
		cout << it->first << " : " << it->second << endl;
	}
}

void Who::run() {
	int menu;

	while (1) {
		cout << "����:1 , �˻�:2 , ����:3 , ��ü ������ ���:4 , ����:5 >> ";
		cin >> menu;
		if (menu == 1)
			insert();
		else if (menu == 2)
			check();
		else if (menu == 3)
			remove();
		else if (menu == 4)
			show();
		else if (menu == 5) {
			cout << "����Ǿ����ϴ�." << endl;
			break;
		}
		else {
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			continue;
		}
	}
}

int main(){
	Who who;
	cout << "***** ��ȣ���� ���α׷� WHO�� �����մϴ�. *****" << endl;
	who.run();
}


