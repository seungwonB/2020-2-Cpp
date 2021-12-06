#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    string tel;
public:
    Person();
    string getName() {
        return name;
    }
    string getTel() {
        return tel;
    }
    void set(string name, string tel);
};

Person::Person() { //���������
    name = "";
    tel = "";
}

void Person::set(string n, string t) { 
    name = n;
    tel = t;
}

int main(){
    Person *person; //������ ����
    int num;
    string name, tel, search, res;
    
    cout << "�����ϰ��� �ϴ� ������ �Է��ϼ��� >> ";
    cin >> num;
    person = new Person[num]; //�Է¹��� ������ �����ϴ� �迭 �Ҵ�
    cout << "�̸��� ��ȭ��ȣ�� �Է����ּ���." << endl;

    for (int i = 0; i < num; i++) {
        cout << "��� " << i + 1 << ">> ";
        cin >> name >> tel;
        person[i].set(name, tel); //����ڿ��� �Է¹ް� �迭�� ����
    }

    cout << "��� ����� �̸��� ";
    for (int i = 0; i < num; i++) {
        cout << person[i].getName() << " ";//�迭�� ����� �̸� ���
    }
    cout << endl << "��ȭ��ȣ�� �˻��մϴ�. �̸��� �Է��ϼ��� >> ";
    cin >> search;
    int res2 = 0;
    for (int i = 0; i < num; i++) {
        if (search == person[i].getName()) {//�˻��� ���� �迭�� �ִ� ���� ������ ��ȭ��ȣ�� ���
            res = person[i].getTel();
            cout << "��ȭ ��ȣ�� " << res << "�Դϴ�. " << endl;
            res2 = 1;
            break; //ã���� �ݺ��� ����
        }
    }
    if (res2 != 1) cout << "�߸� �Է��Ͽ����ϴ�. " << endl;
   
    delete[] person;
    return 0;
}

