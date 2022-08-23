/*
N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.
첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다.
*/
#include<iostream>
using namespace std;

int main() {
    int n, m, sum=0, near=0;
    cin >> n >> m;
    int* card = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    for (int i = 0; i < n - 2;i++) {
        for (int j = i+1; j < n - 1; j++) {
            for (int k = j+1; k < n; k++) {
                sum = card[i] + card[j] + card[k];
                if ( sum == m) {
                    cout << m;
                    return 0;
                }
                else if (near <= sum && sum < m) near = sum;
            }
        }
    }
    cout << near;

    return 0;
}