//첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다. B진법으로 바꿔 출력하는 프로그램을 작성하시오.
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> v;

    while (n != 0) {
        v.push_back(n % b);
        n /= b;
    }


    for (int i = v.size()-1; i >= 0; i--) {
        if (v[i] >= 10) {
            cout << char(v[i] - 10 + 'A');
        }
        else cout << v[i];
    }

    return 0;
}