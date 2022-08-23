/*
택시 기하학에서 두 점 T1(x1,y1), T2(x2,y2) 사이의 거리는 D(T1,T2) = |x1-x2| + |y1-y2|로 구할 수 있다.
두 점 사이의 거리를 제외한 나머지 정의는 유클리드 기하학에서의 정의와 같다.
반지름 R이 주어졌을 때, 유클리드 기하학에서 원의 넓이와, 택시 기하학에서 원의 넓이를 구하는 프로그램을 작성하시오.
*/
#include<iostream>
using namespace std;

#define PI 3.14159265358979323
int main() {
    double r;
    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << r * r * PI << endl;
    cout << 2 * r * r << endl;
    return 0;
}