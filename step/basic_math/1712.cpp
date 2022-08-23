/*A:고정비용 B:가변비용 C:노트북 가격 
예를들어, A=1000, B=70일때 노트북 10대의 생산비용은 1700이다.
손익분기점이 발생하는 판매량을 출력하라. 단, 손익분기점이 존재하지 않으면 -1*/

#include <iostream>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    if(B<C)
        cout << A/(C-B) +1;
    else
        cout << "-1";
    
    return 0;
}
