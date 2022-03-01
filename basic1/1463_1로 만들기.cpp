/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

/*
1 -> 0
2 -> 1
3 -> 1
4 -> (2 or 3) + 1 -> 2
5 -> (4) + 1 -> 3
6 -> (2 or 3 or 5) + 1 -> 2
...
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n+1);

    v[1] = 0;           //n이 1일 경우
    for(int i=2; i<=n; i++){    //각각의 i는 정수 n을 의미한다
        v[i] = v[i-1] + 1;
        if(!(i%3)) v[i] = min(v[i], v[i/3] + 1);
        if(!(i%2)) v[i] = min(v[i], v[i/2] + 1);
    }
    cout << v[n];
    return 0;
}