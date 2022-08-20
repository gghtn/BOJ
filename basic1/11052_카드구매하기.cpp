/*
카드팩의 종류는 카드 1개가 포함된 카드팩 ~ 카드 N개가 포함된 카드팩이 있다.
이 때, 카드 N개를 구매하기 위한 최댓값을 구하시오
예를 들어, 카드팩이 총 4가지 종류가 있고, P1 = 1, P2 = 5, P3 = 6, P4 = 7인 경우에 카드 4개를 갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. 
*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    
}