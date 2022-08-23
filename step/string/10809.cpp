/* 알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램*/
/*<string>의 find함수를 사용할 수 있음
string s;
string alp ="abcdefghijklmnopqrstuvwxyz";
cin>>s;
for(int i = 0; i<alp.length();i++)
    cout << (int)s.find(alp[i]) << " ";
*/
#include <iostream>

using namespace std;

int main() {
    int a, alp[26];
    fill_n(alp, 26, -1);        //배열을 -1로 초기화
    string s;
    cin >> s;

    for (int i = 0; i < s.length();i++) {
        a = int(s[i]) - 97;
        if (alp[a] == -1) alp[a] = i;
    }
    for (int j = 0;j < sizeof(alp)/sizeof(int);j++) {
        cout << alp[j]<< " ";
    }   
    return 0;
}