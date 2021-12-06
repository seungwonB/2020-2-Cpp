#include <iostream>
#include <string>
using namespace std;

class Sugang {
    string subject; //�����
    int number=0; //����
public:
    void sugangshow(); //����� ���� ���
    int getNumber();
    void setSugang(string subject, int number); //������� subject, number �� ����
};

void Sugang::sugangshow() {
    cout << "����� : " << subject << "\t���� : " << number << endl;
}

int Sugang::getNumber() {
    return number;
}

void Sugang::setSugang(string subject, int number) {
    this->subject = subject;
    this->number = number;
}

class Student {
    string hakbeon; //�й�
    Sugang* s; //������û
    int size, totalhak; //�����, �� ��û����
public:
    Student(string hakbeon, int size) :totalhak(0) {
        //�й��� �ʱ�ȭ�ϰ�, size��ŭ Sugang��ü�迭�� �������� �����Ͽ� s�� ����
        this->hakbeon = hakbeon;
        this->size = size;
        s = new Sugang[size];
        setHak();
    }
    Student(Student& su);//��������� ����, ���� ���縦 ���� ���� ������
    void show() {
        cout << "== ������û ���� ==" << endl;
        cout << "�й� : " << hakbeon << endl;
        for (int i = 0; i < size; i++)
            s[i].sugangshow();
        cout << "��û���� : " << totalhak << endl;
    }
    ~Student() { //�Ҹ��� ����
        cout << "Student �޸� �ݳ�" << endl;
    }
    void setHak();//����� ������ �Է� ������ �� ��û ������ ����ϴ� setHak()����
};

Student::Student(Student& su) {
    su.totalhak = 0;
    this->hakbeon = su.hakbeon;
    this->size = su.size;
    s = new Sugang[su.size];
    for (int i = 0; i < su.size; i++) {
        this->s[i] = su.s[i];
    }
    su.setHak();
}

void Student::setHak() { //����� ������ �Է� ������ �� ��û ������ ���
    string subject;
    int number;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ") ����� ������ �Է��ϼ��� >> ";
        cin >> subject >> number;
        s[i].setSugang(subject, number);
        totalhak += number;
    }
}

int main(){
    int index = 0;
    string beon; //�й��� ��������� ����
    int num;
    Student* std[100]; //Student Ÿ���� ũ�Ⱑ 100�� ������ �迭 std ����
    while (index < 100) {
        cout << index + 1 << " >> �й��� �������� ���� �Է��ϼ��� : ";
        cin >> beon >> num;
        if (beon == "0" && num == 0) 
            break;
        std[index] = new Student(beon, num); //�迭 std�� student��ü�� �������� �Ҵ��Ͽ� ����
        index++;
    }
   
    for (int i = 0; i < index; i++) {  //��ü ���� ���� ���
        std[i]->show();
    }
    
    for (int i = 0; i < index; i++) { //���� �Ҵ�� �޸� ��ȯ
        delete std[i];
    }

    return 0;
}

