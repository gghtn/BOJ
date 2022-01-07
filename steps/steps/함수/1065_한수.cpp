/*한수 = 어떤 양의 정수의 각 자리가 등차수열을 이루는 수*/
#include <iostream>
using namespace std;
int hansu(int n){
    int num = 0, a, b, c;
    if(n<100) num = n;
    else{
        num += 99;
        for(int i = 100; i<=n; i++){
            a = i/100, b = (i%100)/10, c = i%10;
            if((a-b) == (b-c)) num++;
        }
    }
    return num;
}

int main(){
    int n;
    cin >> n;
    cout << hansu(n);

    return 0;
}