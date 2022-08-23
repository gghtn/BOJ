/*
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.
(0 ≤ N ≤ 500)
*/

//0이 나오려면 10이 곱해진 경우이므로 N!를 소인수분해 했을 때 2와 5의 개수중 작은 값을 구하면 된다.
//단 5의 개수가 압도적으로 적으므로 5의 개수만 구하면된다.
//1~500에서 5의 배수(5*i)의 개수를 구하면 되는데 즉, N을 5*i로 나눈값이다.
#include <iostream>
using namespace std;

int main() {
    int ans = 0;

    int n;
    cin >> n;

    for (int i = 5; i <= n; i *= 5)
        ans += n / i;

    cout << ans;
    return 0;
}