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

Person::Person() { //공백생성자
    name = "";
    tel = "";
}

void Person::set(string n, string t) { 
    name = n;
    tel = t;
}

int main(){
    Person *person; //포인터 선언
    int num;
    string name, tel, search, res;
    
    cout << "생성하고자 하는 개수를 입력하세요 >> ";
    cin >> num;
    person = new Person[num]; //입력받은 개수를 저장하는 배열 할당
    cout << "이름과 전화번호를 입력해주세요." << endl;

    for (int i = 0; i < num; i++) {
        cout << "사람 " << i + 1 << ">> ";
        cin >> name >> tel;
        person[i].set(name, tel); //사용자에게 입력받고 배열에 저장
    }

    cout << "모든 사람의 이름은 ";
    for (int i = 0; i < num; i++) {
        cout << person[i].getName() << " ";//배열에 저장된 이름 출력
    }
    cout << endl << "전화번호를 검색합니다. 이름을 입력하세요 >> ";
    cin >> search;
    int res2 = 0;
    for (int i = 0; i < num; i++) {
        if (search == person[i].getName()) {//검색한 값과 배열에 있는 값이 같으면 전화번호를 출력
            res = person[i].getTel();
            cout << "전화 번호는 " << res << "입니다. " << endl;
            res2 = 1;
            break; //찾으면 반복문 종료
        }
    }
    if (res2 != 1) cout << "잘못 입력하였습니다. " << endl;
   
    delete[] person;
    return 0;
}

