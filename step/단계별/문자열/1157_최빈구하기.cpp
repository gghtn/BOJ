/*주어진 단어에서 가장 많이 사용된 알파벳을 출력, 여럿 존재할 경우 ?출력*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    bool one = false;
    int max=0, alphabet[26]={};
    int mode;
    string word;
    cin >> word;

    for(int i=0;i<word.length();i++){
        alphabet[toupper(word[i])-'A']++;
    }

    for (int j = 0; j < 26; j++) {
        if (alphabet[j] > max) {
            max = alphabet[j];
            mode = j;
            one = true;
        }
        else if (alphabet[j] == max) {
            one = false;
        }
    }
    if (one == true) cout << char(mode+65);
    else cout << '?';

    return 0;
}