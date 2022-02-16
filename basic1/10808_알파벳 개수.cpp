//알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int main() {
    string s;
    int alphabet[26] = { 0 };
    cin >> s;

    for (int i = 0; i < s.length();i++) {
        alphabet[s[i] - 'a']++;
    }
    for (int i = 0; i < 26;i++) {
        cout << alphabet[i] << ' ';
    }
    return 0;
}