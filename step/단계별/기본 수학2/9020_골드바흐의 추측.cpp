/*
골드바흐 수란  2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다.
또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다.
2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오.
 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T, n;
    bool prime[10000];
    fill_n(prime, 10000, true);
    prime[0] = false;
    prime[1] = false;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        for (int i = 2; i <= sqrt(n); i++) {
            if (prime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        for (int i = 0;i < n / 2;i++) {
            if (prime[n / 2 - i] && prime[n / 2 + i]) {
                cout << n / 2 - i << " " << n / 2 + i << endl;
                break;
            }
        }
    }
    return 0;
}