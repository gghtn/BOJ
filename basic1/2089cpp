// -2진법에서는 (-2)0 = 1, (-2)1 = -2, (-2)2 = 4, (-2)3 = -8을 표현한다. 10진수로 1부터 표현하자면 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001 등이다. -2진수를 출력하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    string s;
    while (n != 0) {
        if (n % (-2) == 0){
            s += '0';
            n /= -2;
        }
        else {
            s += '1';
            n = (n-1) / -2;
        }

    }

    for (int i = s.length()-1; i >= 0; i--) {
        cout << s[i];
    }
    return 0;
}