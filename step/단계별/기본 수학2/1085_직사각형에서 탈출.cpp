/*
현재 위치는 (x, y)에 있다.  직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다.
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int x, y, w, h, m;
    cin >> x >> y >> w >> h;
    m = min(min(x, w - x), min(y, h - y));
    cout << m;
    return 0;
}