/*아파트에 거주를 하는 조건이  “a층의 b호에 살려면 자신의 아래(a-1)층의 1호부터 b호까지 사람들의 수의 합만큼 사람들을 데려와 살아야 한다”는
계약 조항이 있다.
아파트에 비어있는 집은 없고 모든 거주민들이 이 계약 조건을 지키고 왔다고 가정했을 때,
주어지는 양의 정수 k와 n에 대해 k층에 n호에는 몇 명이 살고 있는지 출력하라.
단, 아파트에는 0층부터 있고 각층에는 1호부터 있으며, 0층의 i호에는 i명이 산다
*/
//첫 번째 줄에 Test case의 수 T가 주어진다. 그리고 각각의 케이스마다 입력으로 첫 번째 줄에 정수 k, 두 번째 줄에 정수 n이 주어진다
#include <iostream>
using namespace std;

int getN(int k, int n){
    int result=0;
    if(n == 1) return 1;
    if(k == 0) return n;
    for(int i=1;i<=n;i++){
        result += getN(k-1,i);
    }
    return result;
}

int main(){
    int t, k, n;
    cin >> t;
    for(;t!=0;t--){
        cin >> k >> n;
        cout << getN(k,n) << endl;
    }
    return 0;
}