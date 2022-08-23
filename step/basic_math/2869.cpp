/* 나무 막대의 높이: V, 낮에 오르는 높이: A, 밤에 내려가는 높이: B
정상에 올라간 후는 내려가지 않을 때 나무를 오르는데 며칠이 걸리는지 출력
(1 ≤ B < A ≤ V ≤ 1,000,000,000)*/
#include <iostream>
using namespace std;

int main() {
    int A, B, V, day = 1;
    cin >> A >> B >> V;
    day += (V - A) / (A - B);
    if (V == A) day = 1;
    else if ((V - A) % (A - B) != 0) day++;
    cout << day;
    return 0;
}
