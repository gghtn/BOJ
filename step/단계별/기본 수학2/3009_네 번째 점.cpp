/*
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.
*/
#include<iostream>
using namespace std;

int main(){
    int x, y;
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if(x1 == x2) x = x3;
    else if(x1 == x3) x = x2;
    else x = x1;

    if(y1 == y2) y = y3;
    else if(y1 == y3) y = y2;
    else y = y1;

    cout << x << " " << y;
    return 0;
}