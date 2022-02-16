//알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int main(){
    string s;
    int alphabet[26];
    fill_n(alphabet,26,-1);
    for(int i=0;i<s.length();i++){
        alphabet[s[i]-'a'] = i;
    }
    for (int i = 0; i < 26;i++) {
        cout << alphabet[i] << ' ';
    }
}