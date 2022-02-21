/*
골드바흐의 추측 - 4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오
*/
#include<iostream>
#include<cmath>
using namespace std;

bool prime(int x) {
    if (x == 1) return false;
    for (int i = 2; i <= sqrt(x);i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    while (1) {
        int n, i=1;
        cin >> n;
        if (n == 0) break;
        while (1) {
            a = 2 * i + 1;
            b = n - a;
            if (a > b) {
                cout << "Goldbach's conjecture is wrong." << "\n";
                break;
            }
            else if (prime(a) && prime(b)) {
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
            i++;
        }
    }
    return 0;
}