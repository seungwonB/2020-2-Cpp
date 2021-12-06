#include <iostream>
#include <string>
using namespace std;

class Person {
	string name; //�������������� �̸� (ex �İ�, ��ȣ, �ɸ�)
public:
	Person() { name = ""; } // ���� ������
	Person(string name) { this->name = name; } // �̸��� �Ű������� ���� ������
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
};

class Family { // Family�� Person�� ��ӵǾ� �ִ� �����̴�.
	Person* p; // Person �迭 ������
	int size; // Person �迭�� ũ��. ���� ������ ��
	string group; // ������ (ex �Ѹ�)
public:
	Family(string group, int size); // size ������ŭ Person �迭 ���� ����
	void show(); // ��� ���� ������ ���
	~Family(); // �Ҹ���
	void setName(int index, string name); 
};

Family::Family(string group, int size) {
	p = new Person[size]; // �Է¹��� size��ŭ person�迭 ����
	this->size = size;
	this->group = group;
}

void Family::show() {
	cout << group << " ������ ������ ���� " << size << " �� �Դϴ�. " << endl;
	for (int i = 0; i < size; i++) {
		cout << (i + 1) << ") " << p[i].getName() << endl; // person�迭�� �ִ� �̸� ���
	}
}
void Family::setName(int index, string name) {
	p[index].setName(name); // �Է¹޴� �̸��� index�� ����
	//(p + index)->setName(name); ���� ����
}

Family::~Family() { delete[] p; }

int main(){
	Family* simpson;
	int size = 0; //���� ��
	string group,name; //������, �����������̸�
	cout << "���� ���� �Է��ϼ��� >> ";
	cin >> size;
	cout << "�������� �Է��ϼ��� >> ";
	cin >> group;
	simpson = new Family(group, size); //group�� �������� ������ size���� simpson���� ���� 
	
	for (int i = 0; i < size; i++) {
		cout << (i+1) << ". �̸��� �Է��ϼ���. >> ";
		cin >> name;
		simpson->setName(i,name); //simpson���� ���������� �̸� ����
	}

	simpson->show();
	delete simpson;
	return 0;
 
}



