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
    cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�.)" << endl;
    srand((unsigned)time(0));

    while (1) {
        cout << ">>";
        getline(cin, user);
        if (user == "exit") {
            cout << "���α׷��� �����մϴ�. " << endl;
            break;
        }
        int size = user.length(); //�Է¹��� ���ڿ��� ����
        while (true) {
            num = rand() % size; //0���� ���̱��� ����
            if (user[num] != ' ') break; //������ ���ڿ��� ��ȯ�Ǹ� �ȵǱ� ������ �װ��� �����ֱ� ����.
        }
        rnd = rand() % 26; //0���� 26���� ���� ����(���ĺ��� 26��)
        change = user.replace(num, 1, arr[rnd]); //���ڿ����� ������ �ε�������, 1����, arr�迭�� �ִ� ������ ���� ��ȯ
        cout << user << endl;
    }
    return 0;
}   


