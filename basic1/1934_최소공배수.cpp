#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(a % b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    int t, a, b;
    cin >> t;
    for(;t!=0;t--){
        cin >> a >> b;
        cout << (a*b)/gcd(a,b) <<'\n';
    }
    return 0;
}