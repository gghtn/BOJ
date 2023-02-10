#include <iostream>
#include<cmath>
using namespace std;

#define MAX_NUM     1000001

//bool prime(int x) {
//    if (x == 1) return false;
//    for (int i = 2; i <= sqrt(x); i++) {
//        if (x % i == 0) return false;
//    }
//    return true;
//}

bool bArr[MAX_NUM];
void Eratos()
{
    memset(bArr, 1, sizeof(bool) * MAX_NUM);
    for (int i = 2; i < MAX_NUM; ++i)
    {
        if (bArr[i] == 0) continue;

        for (int j = 2 * i; j < MAX_NUM; j += i)
            bArr[j] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Eratos();
    int a, b;
    while (1) {
        int n, i = 1;
        cin >> n;
        if (n == 0) break;
        while (1) {
            a = 2 * i + 1;
            if (bArr[a])
            {
                b = n - a;
                if (a > b) {
                    cout << "Goldbach's conjecture is wrong." << "\n";
                    break;
                }
                if (bArr[b]) {
                    cout << n << " = " << a << " + " << b << "\n";
                    break;
                }
            }
            i++;
        }
    }
    return 0;
}