//골드바흐의 추측: 2보다 큰 짝수는 두 소수의 합으로 나타낼 수 있다. 짝수 N을 두 소수의 합으로 나타내는 표현을 골드바흐 파티션이라고 한다. 짝수 N이 주어졌을 때, 골드바흐 파티션의 개수를 구해보자.
//일반적인 방법은 시간초과가 나올 가능성이 높다. 1929번, 9020번과 유사하다.
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool prime[1000001];
    fill_n(prime, 1000001, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= sqrt(1000000); i++) {      //에라토스테네스의 체
        if (prime[i]) {
            for (int j = 2 * i;j <= 1000000;j += i) {
                prime[j] = false;
            }
        }
    }


    int t, n;
    cin >> t;
    for (;t != 0;t--) {
        int cnt = 0;
        cin >> n;
        for (int i = 2; i <= n / 2; i++) {
            if (prime[i] && prime[n - i]) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}