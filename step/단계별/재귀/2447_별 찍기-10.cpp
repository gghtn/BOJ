/*
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다.
*/
#include <iostream>
using namespace std;

void star(int i,int j, int n) {
    if (i/n % 3 == 1 && j/n % 3 == 1) cout << " ";
    else if (n / 3 == 0) cout << "*";
    else star(i, j, n / 3);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            star(i, j, n);
        }
        cout << endl;
    }
    return 0;
}