/*
하노이 탑 이동 횟수를 출력하는 프로그램
n개의 원판을 옮기는 방법은 n-1개의 원판을 2번으로 -> 가장큰 원판을 3번으로 -> n-1개의 원판을 2번에서 3번으로
cout사용시 시간초과가 떠서 printf를 사용함
*/
#include<iostream>
#include<cmath>
using namespace std;

void hanoi(int start, int mid, int end, int n) {
    if (n == 1) printf("%d %d\n", start, end);
    else {
        hanoi(start, end, mid, n - 1);  //n-1개의 원판을 1->2로
        printf("%d %d\n", start, end);  //마지막원판을 1->3으로
        hanoi(mid, start, end, n - 1);  //2의 n-1개의 원판을 3으로
    }
}

int main() {
    int n;
    cin >> n;
    cout << (int)pow(2, n) - 1 << endl;
    hanoi(1, 2, 3, n);
    return 0;
}