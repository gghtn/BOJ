#include <iostream>
using namespace std;

void selfN(int a){
    int arr[10001] = {0,};
    for(int i=a; i<10000;i++){
        int n = i + i/1000 + (i%1000)/100 + (i%100)/10 + i%10;
        if(n <= 10000) arr[n] = 1;
    }
    for(int i = a;i<10000; i++){
        if(arr[i] != 1) cout<< i <<endl;
    }
}

int main(){
    selfN(1);
}