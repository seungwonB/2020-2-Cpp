#include <iostream>
#include <string>
using namespace std;

class Ram {
	char mem[100 * 1024]; // 100kb �޸�. �� ������ �� ����Ʈ�̹Ƿ� char Ÿ�� ���.
	int size;
public:
	Ram(); // mem �迭�� 0���� �ʱ�ȭ �ϰ� size�� 100*1024�� �ʱ�ȭ
	~Ram(); // "�޸� ���ŵ�" ���ڿ� ���
	char read(int address); // address �ּ��� �޸� ����Ʈ ����
	void write(int address, char value); // address �ּҿ� �� ����Ʈ�� value ����
};

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; ++i)
		mem[i] = 0;
}
Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}
char Ram::read(int address) {
	if (address < 0 || address > size) {
		cout << "read �ּҰ� ������ ����� ���� �߻�" << endl;
		return -1;
	}
	else {
		return mem[address];
	}
}
void Ram::write(int address, char value) {
	if (address > size)
		cout << "write �ּҰ� ������ ����� ���� �߻�" << endl;
	else {
		mem[address] = value;
	}
}

int main() {
	Ram ram;
	ram.write(100, 20); // 100 ������ 20 ����
	ram.write(101, 30); // 101 ������ 30 ����
	ram.write(400000, 37); //400000 ������ 37 ����

	cout << "ram.read(345000) :" << (int)(ram.read(345000)) << endl; //�ּ� ������ ����� -1 ��ȯ
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res); // 102 ������ 50 ����
	cout << "102 ������ �� = " << (int)ram.read(102) << endl; // 102 ���� �޸� �� ���
	cout << "program finish" << endl;
	return 0;
}

