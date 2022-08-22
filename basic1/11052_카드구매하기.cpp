/*
카드팩의 종류는 카드 1개가 포함된 카드팩 ~ 카드 N개가 포함된 카드팩이 있다.
이 때, 카드 N개를 구매하기 위한 최댓값을 구하시오
예를 들어, 카드팩이 총 4가지 종류가 있고, P1 = 1, P2 = 5, P3 = 6, P4 = 7인 경우에 카드 4개를 갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, total = 0;
    cin >> n;

    vector<int> v1(n + 1);
    vector<float> v2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v1[i];
        v2[i] = v1[i] / i;
    }

    while (true) {
        if (n == 0) break;
        int index = max_element(v2.begin(), v2.end()) - v2.begin();
        if (index <= n) {
            n -= index;
            total += v1[index];
        }
        else v2[index] = 0;
    }
    cout << total;
}