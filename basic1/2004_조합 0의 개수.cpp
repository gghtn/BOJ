//조합의 끝자리 0의 개수를 출력하는 프로그램
//1676_팩토리얼 0의 개수와 유사하지만 나눗셈이 포함되어 있기 때문에 5와 2중에 더작은 값을 구해야함 
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, m, two = 0, five = 0;      //정수 오버플로우 주의
    cin >> n >> m;

    //5의 개수
    for (long long i = 5;i <= n;i *= 5) {
        five += n / i;
    }
    for (long long i = 5;i <= n - m;i *= 5) {
        five -= (n - m) / i;
    }
    for (long long i = 5;i <= m;i *= 5) {
        five -= m / i;
    }

    //2의 개수
    for (long long i = 2;i <= n;i *= 2) {
        two += n / i;
    }
    for (long long i = 2;i <= n - m;i *= 2) {
        two -= (n - m) / i;
    }
    for (long long i = 2;i <= m;i *= 2) {
        two -= m / i;
    }
    
    cout << min(five, two);
    return 0;
}