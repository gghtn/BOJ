/*숫자 1,2,3,4,5,6,7,8,9,0가 있고 숫자 1을 걸려면 총 2초가 필요하다.
한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다. 숫자는 알파벳으로
표현하고 알파벳을 입력하면 총걸리는 시간을 출력한다*/
// 2 : ABC, 3: DEF, 4: GHI, 5:JKL, 6:MNO, 7: PQRS, 8:TUV, 9: WXYZ

#include <iostream>
using namespace std;

int main() {
    int total = 0;
    int time[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
    string word;
    cin >> word;
    for (int i = 0; i < word.length();i++) {
        total += time[word[i] - 'A'];
    }
    cout << total;

    return 0;
}