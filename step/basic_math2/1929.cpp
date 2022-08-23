/*
M이상 N이하의 소수를 모두 출력하는 프로그램
단순히 소수를 판별하는 함수와 반복문을 사용하면 시간초과가 뜬다
때문에 2, 3, 5, 7....의 배수를 제거하는 방식으로 소수 이외의 수를 제거해나간다
cout을 사용했을 때 시간초과가 나와 printf를 사용했다.
 */
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int M, N;
    bool prime[1000001];
    cin >> M >> N;

    fill_n(prime, 1000001, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2;i <= sqrt(N);i++) {
        if (prime[i]) {
            for (int j = 2 * i;j <= N;j += i) {
                prime[j] = false;
            }
        }
    }
    for (int i = M;i <= N;i++) {
        if (prime[i]) printf("%d\n", i);
    }
    return 0;
}