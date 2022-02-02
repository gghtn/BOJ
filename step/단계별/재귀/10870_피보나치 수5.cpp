/*
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
피보나치 수를 구하는 프로그램
*/
#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n<=1) return n;
    int result = fibonacci(n-1)+fibonacci(n-2);
    return result;
}

int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}