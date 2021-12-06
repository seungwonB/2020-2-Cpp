#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    string user;
    string change;
    int size;
    int num, rnd;
    string arr[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)" << endl;
    srand((unsigned)time(0));

    while (1) {
        cout << ">>";
        getline(cin, user);
        if (user == "exit") {
            cout << "프로그램을 종료합니다. " << endl;
            break;
        }
        int size = user.length(); //입력받은 문자열의 길이
        while (true) {
            num = rand() % size; //0부터 길이까지 랜덤
            if (user[num] != ' ') break; //공백은 문자열로 교환되면 안되기 때문에 그것을 피해주기 위함.
        }
        rnd = rand() % 26; //0부터 26까지 랜덤 숫자(알파벳이 26개)
        change = user.replace(num, 1, arr[rnd]); //문자열에서 랜덤의 인덱스부터, 1개를, arr배열에 있는 랜덤의 값과 교환
        cout << user << endl;
    }
    return 0;
}   


