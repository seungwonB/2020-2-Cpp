[���α׷� �ҽ�]
#include <iostream>
#include <string>
using namespace std;

class Dept {
	int size; //scores �迭�� ũ��
	int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ�
public:
	Dept(int size); //�Ű������� ���� �迭 ũ�⸸ŭ scores �迭 ����
	Dept(Dept& dept); //���� ������
	~Dept(); //�Ҹ���
	int getSize(); //�迭 ũ�� ��ȯ
	void read(); //size ��ŭ �⺸�忡�� ������ �о� scores �迭�� ����
	bool isOver60(int index); //index�� �л��� ������ 60���� ũ�� true ����
};

Dept::Dept(int size) {
	this->size = size;
	scores = new int[size];
}

Dept::Dept(Dept& dept) {
	this->size = dept.size;
	scores = new int[size];
	
	for (int i = 0; i < dept.size; i++) {
		this->scores[i] = dept.scores[i];	//scores�迭�� ����
	}
}

Dept::~Dept() {
	delete[] scores;
}

int Dept::getSize() {
	return size;
}

void Dept::read() {
	int num;
	for (int i = 0; i < size; i++) {
		cout << "[" << (i + 1) << "] ";
		cin >> num;
		scores[i] = num;
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60)
		return true;
	else
		return false;
}

int countPass(Dept& com) {
	int cnt = 0;
	for (int i = 0; i < com.getSize(); i++) {
		if (com.isOver60(i))
			cnt++;
	}
	return cnt;
}

int main(){
	Dept* com;
	int cnt;
	cout << "�л� ���� �Է��ϼ��� >> ";
	cin >> cnt;
	com = new Dept(cnt);
	com->read();
	int n = countPass(*com);
	cout << "60�� �̻��� " << n << "��" << endl;
	delete com;
}



