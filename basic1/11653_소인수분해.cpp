#include<iostream>
using namespace std;

int main(){
    int n, x=2;
    cin >> n;
    while(n!=1){
        if(n % x == 0){
            cout << x << "\n";
            n /= x;
        }
        else x++;
    }
    return 0;
}