/*자연수 M과 N이 주어졌을 때 M과 N사이에 있는 소수의 합과 최솟값을 출력하라*/
#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int x){
    if(x == 1) return false;
    for(int i=2;i <= sqrt(x);i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    int m, n, sum=0, min=0;
    cin >> m >> n;
    for(int i=m;i<=n;i++){
        if(isPrime(i)){
            sum += i;
            if(min == 0) min = i;
        }
    }

    if(sum!=0) cout << sum << "\n" << min<<endl;
    else cout << "-1" <<endl;
    return 0;
}