//양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오
//유클리드 호제법
#include<iostream>
#include<vector>
using namespace std; 

int gcd(int a, int b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main() {
    int t;
    vector<int> v;
    cin >> t;

    for (;t != 0;t--) {
        int n, x;
        long long sum = 0;  //1,000,000이 100개 있을 경우 즉, 최댓값이 49억5천만이므로 int형을 넘는다.
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(v[i], v[j]);
            }
        }
        cout << sum << "\n";
        v.clear();
    }
    return 0;
} 