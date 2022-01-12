/*그룹 단어란 동일한 문자가 연속해서 나타나는 문자를 말한다
예를들어, abc와 aabbcc의 경우 각 a,b,c가 연속해서 나타나므로 그룹단어이지만
abca의 경우 a가 연속해서 나타나지 않으므로 그룹단어가 아니다
단어 N개를 입력받아 그룹단어의 개수를 출력하라*/

#include <iostream>
using namespace std;

int main() {
    int N, count = 0;
    string word;
    cin >> N;
    for (int i = 0; i < N; i++) {
        bool group = true;
        cin >> word;
        for (int j = 1;j < word.length();j++) {
            if (word[j - 1] != word[j]) {
                for (int k = j + 1;k < word.length();k++) {
                    if (word[j - 1] == word[k]) {
                        group = false;
                        break;
                    }
                }
            }
            if (group == false) break;
        }
        if (group == true) count++;
    }
    cout << count;
}