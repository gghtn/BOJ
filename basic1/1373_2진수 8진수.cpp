//2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int main() {
    string binary;
    cin >> binary;
    int len = binary.length();

    for (int i = 0; i < len;) {
        if ((len - i) % 3 == 2) {
            cout << (binary[i] - '0') * 2 + (binary[i + 1] - '0');
            i = i + 2;
        }
        else if ((len - i) % 3 == 1) {
            cout << binary[i] - '0';
            i = i + 1;
        }
        else {
            cout << (binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + (binary[i + 2] - '0');
            i = i + 3;
        }
    }

    return 0;
}