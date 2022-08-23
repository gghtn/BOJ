//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
//첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
/* 
1 or 2로 n을 만드는 방법의 수와 같다.
n = 1 -> 1
n = 2 -> 2
n = 3 -> 3
n = 4 -> 5
n = 5 -> 8
...
n = 9 -> n(8) + n(7) = 55 임을 알 수 있다.
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[10001]={0};
    cin >> n;

    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] %= 10007;        //n의 값이 큰 경우 자료형의 범위를 벗어나므로
    }
    cout << arr[n];

    return 0;
}