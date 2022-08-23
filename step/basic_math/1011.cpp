/*
x에서 y로 이동할 때 처음 1을 이동한 후 다음부터는 이전 이동거리의 -1에서 +1사이만큼 이동할 수 있다.
예를들어, 처음 1이동후 다음이동은 0, 1, 2가 될 수 있고 여기서 2를 이동하면 다음은 1,2,3을 이동할 수있다.
하지만 마지막 y에 도착하기 전엔 반드시 1만 이동해야한다. 최소 이동 횟수를 출력하라
*/

/*
규칙을 파악해야 하는 문제로 제곱수일 경우 제곱근에 2를 곱한값에 1을 뺀 값이 이동수이다
제곱수사이의 수는 제곱근의 반올림이 제곱수보다 큰지 같은지 알아내면 된다.
*/
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int T,num;
    double x, y, distance;
    cin >> T;
    for (int i = 0;i < T;i++) {
        cin >> x >> y;
        distance = y - x;
        double sqr = sqrt(distance);    
        int sqr_round= round(sqr);

        if (sqr == sqr_round) num = 2 * sqr - 1;        //거리가 제곱수일 경우
        else if (sqr > sqr_round) num = 2 * sqr_round;  //제곱근의 반올림이 제곱수와 같은 경우
        else num = 2 * sqr_round - 1;                   //제곱근의 반올림이 제곱수보다 큰경우
        cout << num << endl;
    }
    return 0;
}
