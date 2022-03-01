//2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
/*
타일링1과 마찬가지로 규칙을 찾으면 된다.
n=1 -> 1
n=2 -> 3    n(1)*2+1
n=3 -> 5    n(2)*2-1
n=4 -> 11   n(3)*2+1
n=5 -> 21   n(4)*2-1
*/
#include<iostream>
using namespace std;

int main(){
    int n;
    int arr[1001] = {0};
    cin >> n;

    arr[1] = 1;
    for(int i=2; i<=n; i++){
        if(!(i%2)) arr[i] = arr[i-1]*2 + 1;
        else arr[i] = arr[i-1]*2 - 1;
        arr[i] %= 10007;
    }
    cout << arr[n];

    return 0;
}