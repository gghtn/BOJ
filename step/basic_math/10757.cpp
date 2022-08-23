/*(0 < A,B < 1010000)일 때 A+B를 출력하는 프로그램 작성*/
#include<iostream>
using namespace std;

int main() {
    string a, b, big, small;
    int tmp;
    bool t = false;         //올림수가 있는지
    cin >> a >> b;
    int arr_a[10001] = { 0, }, arr_b[10001] = { 0, };
    if (a.length() > b.length()) {
        big = a;
        small = b;
    }
    else {
        big = b;
        small = a;
    }
    tmp = big.length() - small.length();

    for (int i = 1; i < big.length()+1; i++) {
        arr_a[i] = big[i - 1] - '0';
    }
    for (int j = 1 + tmp; j < small.length()+1+tmp;j++) {
        arr_b[j] = small[j - 1 - tmp] - '0';
    }

    for (int k = big.length(); k >= 0; k--) {
        int sum;
        if (t == true) sum = arr_a[k] + arr_b[k] + 1;
        else sum = arr_a[k] + arr_b[k];

        arr_a[k] = sum % 10;
        if (sum / 10 == 1) t = true;
        else t = false;
    }
    if (arr_a[0] != 0) cout << arr_a[0];
    for (int i = 1; i < big.length() + 1; i++) {
        cout << arr_a[i];
    }
    return 0;
}