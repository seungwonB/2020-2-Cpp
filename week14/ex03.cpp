[���α׷� �ҽ�]
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Nation {
	string capital;
	string nation;
public:
	Nation() {}
	void set(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getNation() { return nation; }
	string getCapiatal() { return capital; }
	void add();
};

void Nation::add() {
	vector<Nation> v;
	Nation n;
	int x; //�޴� ���ϴ� ����
	string a1, a2; //�߰��Ǵ� ����� ���� ����
	string quiz; //���� ���ߴ� ����
	bool loop = true; //�ݺ��� Ż���� ���� ����
	int cnt = 0; //������ ���� ����
	string vnation[] = { "���ѹα�", "ȣ��", "�̱�" , "�ɶ���", "�븣����", "��������", "������", "������", "��������" };
	string vcapital[] = { "����", "ĵ����", "������", "���Ű", "������", "������", "����Ȧ��", "�ĸ�", "������" };

	for (int i = 0; i < 9; i++) {
		v.push_back(n); //���Ϳ� ����
		v[i].set(vnation[i], vcapital[i]); //�迭�� �ִ� ������ ��� ����
	}

	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****" << endl;

	while (1) {
		cout << "���� �Է�: 1, ����: 2, ����: 3 >>";
		cin >> x;
		
		if (x == 1) { //�����Է�
			cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
			cout << "����� ������ �Է��ϼ���.(no no �̸� �Է³�)" << endl;
			int i = v.size();
			while (1) {
				cout << (i + 1) << ">>"; 
				cin >> a1 >> a2; 
				i++;
				if (a1 == "no" && a2 == "no") //no no �Է½� �߰� ����
					break;
				 
				for (int j = 0; j < v.size(); j++) { 
					if (v[j].getNation() == a1) { //�̹� �ִ� ���� �Է��ҽ�
						cout << "�̹� �����ϴ� �����Դϴ�. " << endl;
						loop = false;
						break; 
					}
				}

				if (loop) { //�Է¹��� ������ ��� ����
					v.push_back(n);
					v[i-1].set(a1, a2);
				}
			}
		}
		else if (x == 2) { //����
			for (int i = 0; i < v.size(); i++) { //������ ũ�⸸ŭ �ݺ�
				cout << v[i].getNation() << "�� ������? ";
				cin >> quiz;
				if (quiz == "exit")
					break;
				if (quiz == v[i].getCapiatal()) { //������ ���� ��
					cnt++;
					cout << "Correct !!" << endl;
				}
				else //Ʋ�� ��
					cout << "NO !!" << endl;
			}
			cout << "�� ���� ������ " << cnt << "�� �Դϴ�." << endl; //���� ������ �߰��غ�.
		}else if (x == 3) { //����
			cout << "����Ǿ����ϴ�." << endl;
			break;
		}
		else { //����ó��
			cout << "�߸��Է��Ͽ����ϴ�." << endl;
			continue;
		}
		
	}
}

int main(){
	Nation nation;
	nation.add();
}



