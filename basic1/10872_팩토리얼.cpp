#include<iostream>
using namespace std;

int main(){
    int n, result = 1;
    cin >> n;
    for(;n!=0;n--){
        result *= n;
    }
    cout << result;
    return 0;
}