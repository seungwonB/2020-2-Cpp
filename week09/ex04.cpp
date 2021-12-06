#include <iostream>
#include <string>
using namespace std;

class Sugang {
    string subject; //과목명
    int number=0; //학점
public:
    void sugangshow(); //과목과 학점 출력
    int getNumber();
    void setSugang(string subject, int number); //멤버변수 subject, number 값 설정
};

void Sugang::sugangshow() {
    cout << "과목명 : " << subject << "\t학점 : " << number << endl;
}

int Sugang::getNumber() {
    return number;
}

void Sugang::setSugang(string subject, int number) {
    this->subject = subject;
    this->number = number;
}

class Student {
    string hakbeon; //학번
    Sugang* s; //수강신청
    int size, totalhak; //과목수, 총 신청학점
public:
    Student(string hakbeon, int size) :totalhak(0) {
        //학번을 초기화하고, size만큼 Sugang객체배열을 동적으로 생성하여 s에 저장
        this->hakbeon = hakbeon;
        this->size = size;
        s = new Sugang[size];
        setHak();
    }
    Student(Student& su);//복사생성자 구현, 깊은 복사를 위한 복사 생성자
    void show() {
        cout << "== 수강신청 내역 ==" << endl;
        cout << "학번 : " << hakbeon << endl;
        for (int i = 0; i < size; i++)
            s[i].sugangshow();
        cout << "신청학점 : " << totalhak << endl;
    }
    ~Student() { //소멸자 구현
        cout << "Student 메모리 반납" << endl;
    }
    void setHak();//과목과 학점을 입력 받으면 총 신청 학점을 계산하는 setHak()구현
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

void Student::setHak() { //과목과 학점을 입력 받으며 총 신청 학점을 계산
    string subject;
    int number;

    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ") 과목과 학점을 입력하세요 >> ";
        cin >> subject >> number;
        s[i].setSugang(subject, number);
        totalhak += number;
    }
}

int main(){
    int index = 0;
    string beon; //학번과 수강과목수 저장
    int num;
    Student* std[100]; //Student 타입의 크기가 100인 포인터 배열 std 선언
    while (index < 100) {
        cout << index + 1 << " >> 학번과 수강과목 수를 입력하세요 : ";
        cin >> beon >> num;
        if (beon == "0" && num == 0) 
            break;
        std[index] = new Student(beon, num); //배열 std에 student객체를 동적으로 할당하여 저장
        index++;
    }
   
    for (int i = 0; i < index; i++) {  //전체 수강 내역 출력
        std[i]->show();
    }
    
    for (int i = 0; i < index; i++) { //동적 할당된 메모리 반환
        delete std[i];
    }

    return 0;
}

