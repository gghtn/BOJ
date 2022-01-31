/*
베르트랑 공준은 임의의 자연수 n에 대하여 n보다 크고 2n보다 작거나 같은 소수는 적어도 하나
존재한다는 내용을 담고 있다. 자연수가 n이 주어졌을 때 n보다 크고, 2n보다 작거나 같은 소수의 개수를 구하는 프로그램을 작성하시오. 
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[250000] = { };
    while (1) {
        int num = 0;
        cin >> n;
        if (n == 0) break;
        for (int i = 2; i <= 2 * n; i++) {
            for (int j = i * 2;j <= 2 * n; j += i) {
                arr[j] = 1;
            }
        }

        for (int i = n + 1; i <= 2 * n; i++) {
            if (arr[i] == 0) num++;
        }
        cout << num << endl;
    }
    return 0;
}