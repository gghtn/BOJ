//8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.
#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    int n;
    vector<int> binary;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        n = s[i] - '0';
        if (n >= 4) {
            binary.push_back(1);
            n -= 4;
        }
        else binary.push_back(0);

        if (4 > n && n > 1) {
            binary.push_back(1);
            n -= 2;
        }
        else binary.push_back(0);

        if (n == 1) binary.push_back(1);
        else binary.push_back(0);
        
    }

    if (binary[0] != 0) cout << binary[0] << binary[1];
    else if (binary[1] != 0) cout << binary[1];
    for (int i = 2; i < binary.size(); i++) {
        cout << binary[i];
    }
    return 0;
}