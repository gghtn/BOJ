/*
A진법을 B진법으로 변환하는 프로그램  첫 줄에는 진법 A와 진법 B가 주어진다. A와 B는 모두 2이상 30이하의 자연수
두 번째 줄에는 A진법으로 나타낸 숫자의 자리수의 개수 m(1 ≤ m ≤ 25)이 주어진다.
세 번째 줄에는 A진법을 이루고 있는 숫자 m개가 공백을 구분으로 높은 자릿수부터 차례대로 주어진다. 각 숫자는 0이상 A미만임이 보장된다. 
*/
//진법변환1,2와 비슷하다.
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int m;  //자릿수의 개수
    cin >> m;

    int n, total=0;
    for(int i=m-1; i >=0; i--){
        cin >> n;
        total += pow(a,i) * n;
    }

    vector<int> v;
    while(total != 0){
        v.push_back(total%b);
        total /= b;    
    }

    for(int i=v.size()-1; i>=0; i--){
        cout << v[i] << ' ';
    }
    return 0;
}