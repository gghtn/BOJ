/*
직각삼각형인지 알아내는 프로그램을 작성하시오.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int x, y, z;
    while (1) {
        cin >> x >> y >> z;
        if (x == 0 && y == 0 && z == 0) break;
        if (x > y) swap(x, y);
        if (y > z) swap(y, z);
        if ((x * x + y * y) == z * z) cout << "right" << endl;
        else cout << "wrong" << endl;
    }

    return 0;
}