//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
/*
n=1 -> 1
n=2 -> 2
n=3 -> 4
n=4 -> 7
n=5 -> 13
n=6 -> 24
n=7 -> 44
...
*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    vector<int> v(11);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for (int i = 4; i <= 10; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << v[n] << "\n";
    }

    return 0;
}