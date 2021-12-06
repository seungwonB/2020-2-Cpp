#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:
	Player() { name = ""; }
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

class Game {
	Player* p;
	string first, second;
public:
	Game() {
		first = "tree"; //tree�� �ʱ�ȭ
	}
	~Game() {
		delete[] p; //�޸� ��ȯ
	}
	void word();
};

void Game::word() {
	int count;
	string str;
	
	cout << "�����ձ� ������ �����մϴ�." << endl;
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	cin >> count;
	p = new Player[count]; //�Է¹��� ���ڸ�ŭ �迭 ����

	for (int i = 0; i < count; i++) {
		cout << "�������� �̸��� �Է��ϼ���.(��ĭ����) >> ";
		cin >> str;
		p[i].setName(str); //������ �迭�� �Է¹��� �� ����
	}

	cout << "�����ϴ� �ܾ�� tree�Դϴ�. " << endl;
	int index = 0;
	
	while (true) {
		cout << p[index].getName() << " >> "; //������� �Է¹��� �̸� �� ���
		cin >> second; //����ڵ��� �Է��ϴ� �ܾ�
		int size = first.size(); //ù��° �ܾ��� ������ = 4(tree)
		if (first.at(size - 1) == second.at(0)) { //at�� index���� ���ڸ� �����ϴ� ���̹Ƿ� 1�� ���ش�. ���� �ܾ� ������ ���ڿ� �� ���� �ܾ� ù��° ���ڸ� ���Ѵ�.
			first = second; // ������ �Ŀ� �Էµ� �ܾ ���� �Էµ� �ܾ�� ���ϱ� ���� �ٽ� first�� �����Ѵ�.
		}
		else { //���� ������ ����
			cout << endl << p[index].getName() << "��(��) �����ϴ�.!"; 
			break;
		}
		++index;
		if (index >= count) index = 0; //index���� count(�Է¹��� ���� ��)������ Ŀ���� �ȵȴ�.
	}
}
int main() {
	Game g;
	g.word();
	return 0;
}

