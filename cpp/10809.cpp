#include <iostream>
#include <string>
using namespace std;

int main() {
    int alphabet[26];
    fill_n(alphabet, 26, -1); // c - memset

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if(alphabet[str[i] - 97] == -1) alphabet[str[i] - 97] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
    return 0;
}