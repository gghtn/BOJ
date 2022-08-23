/*
ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 예를 들어, "One is 1"을 ROT13으로 암호화하면 "Bar vf 1"이 된다.
문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0;i < s.length();i++) {
        if (s[i] != ' ' && !('0' <= s[i] && s[i] <= '9')) {
            if ('A' <= s[i] && s[i] <= 'Z') {
                if (s[i] + 13 > 'Z') s[i] -= 13;
                else s[i] += 13;
            }
            else {
                if (s[i] + 13 > 'z') s[i] -= 13;
                else s[i] += 13;
            }
        }
    }
    cout << s;
    return 0;
}