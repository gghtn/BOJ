/*
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
2원의 교차점의 개수를 구하는 문제이다.
*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int t, x1, y1, r1, x2, y2, r2;
    cin >> t;
    for (int i = 0;i < t;i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double R = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        int sub = abs(r2 - r1);

        if (R == 0 && r1 == r2)  cout << "-1" << endl;
        else if (sub < R && R < r1 + r2) cout << "2" << endl;
        else if (R == r1 + r2 || R == sub) cout << "1" << endl;
        else cout << "0" << endl;

    }
    return 0;
}