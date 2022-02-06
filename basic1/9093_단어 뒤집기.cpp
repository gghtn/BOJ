/*
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오. 단, 단어의 순서는 바꿀 수 없다. 단어는 영어 알파벳으로만 이루어져 있다.
stack을 사용할 수도 있음
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin.ignore(); //cin과 getline을 같이 쓰기 위해서 버퍼를 지워야 함
    for (int j = 0;j < n;j++) {
        int start = 0;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+start,s.begin()+i);
                start = i + 1;
            }
            else if(i == s.length()-1) reverse(s.begin() + start, s.begin() + i + 1);
        }
        cout << s << endl;
    }
    return 0;
}