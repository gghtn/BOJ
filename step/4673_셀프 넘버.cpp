#include <iostream>
using namespace std;

int selfN(int a){
    int n = a;
    for(;a != 0; a /= 10){
        n += a%10;
    }
    return n;
}

int main(){
    int arr[10001] = {0,};
    for(int i =1; i<10000;i++){
        if(arr[i] = 0) cout << i << endl;
        arr[selfN(i)] = 1;
    }
    return 0;
}