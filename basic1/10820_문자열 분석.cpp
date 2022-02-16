//문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.
#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int small = 0, big = 0, num = 0, space = 0;
        for (int i = 0;i < s.length();i++) {
            if (s[i] == ' ') space++;
            else if ('0' <= s[i] && s[i] <= '9') num++;
            else if ('A' <= s[i] && s[i] <= 'Z') big++;
            else small++;
        }
        cout << small << ' ' << big << ' ' << num << ' ' << space << '\n';
    }
    return 0;
}