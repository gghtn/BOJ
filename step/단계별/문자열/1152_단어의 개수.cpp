/*영어 대소문자와 공백으로 이루어진 문자열이 주어졌을 때 몇개의 단어가 있는지 출력*/
/*공백을 포함한 문자열은 getline함수를 사용한다*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int totalWord = 0;
    string s;
    getline(cin, s);

    if (s.empty()) {
        cout << "0";
        return 0;
    }
    
    totalWord = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') totalWord++;
    }

    if (s[0] == ' ') totalWord--;
    if (s[s.length() - 1] == ' ') totalWord--;
    cout << totalWord;

    return 0;
}