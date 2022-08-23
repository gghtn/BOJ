//최대공약수를 이용하는 문제
#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int n, s, a, result=0;
    cin >> n >> s;
    for (;n != 0;n--) {
        cin >> a;
        if (result == 0) result = abs(s - a);
        else result = gcd(result, abs(s - a));
    }
    cout << result;
    return 0;
}