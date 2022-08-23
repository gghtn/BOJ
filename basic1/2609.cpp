//두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
#include<iostream>
using namespace std;

int gcd(int a, int b){
    int i=2, result=1;
    while(1){
        if(i > a || i > b) break;
        if(a%i == 0 && b%i == 0){
            a = a/i;
            b = b/i;
            result *= i;
        }
        else i++;
    }
    return result;
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b); //최대공약수 x 최소공배수 = 두 수의 곱
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << '\n' << lcm(a,b);
}

/*
최대공약수 유클리드 호제법
int gcd(int a, int b){
    if(a % b == 0) return b;
    else return gcd(b,a%b);
}
*/