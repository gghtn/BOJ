#include <iostream>
using namespace std;

void selfN(int a){
    int arr[10001] = {0,},n;
    for(int i=a; i<10000;i++){
        if(arr[i] != 1) cout<< i <<endl;
        n = i + i/1000 + (i%1000)/100 + (i%100)/10 + i%10;
        if(n <= 10000) arr[n] = 1;
    }
}

int main(){
    selfN(1);
    return 0;
}

