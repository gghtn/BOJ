#include<iostream>
#include <cmath>
using namespace std;

bool is_prime(int x){
    if(x == 1) return false;
    for(int i=2; i<=sqrt(x); i++){
        if(x % i == 0) return false;
    }
    return true; 
}

int main(){
    int N, x, num=0;
    cin>>N;
    for(;N!=0;N--){
        cin >> x;
        if(is_prime(x)) num++;
    }
    cout << num;
    return 0;
}