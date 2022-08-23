/*
종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다. 제일 작은 종말의 숫자는 666이고, 그 다음으로 큰 수는 1666, 2666, 3666, .... 과 같다.
따라서, 숌은 첫 번째 영화의 제목은 세상의 종말 666, 두 번째 영화의 제목은 세상의 종말 1666 이렇게 이름을 지을 것이다. 일반화해서 생각하면, N번째 영화의 제목은 세상의 종말 (N번째로 작은 종말의 숫자) 와 같다.
숌이 만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오
*/
#include<iostream>
using namespace std;

int main() {
    int n, cnt = 666, count = 0;
    cin >> n;
    while (1) {
        int tmp = cnt;
        while(tmp >= 666) {
            if (tmp % 1000 == 666) {
                count++;
                break;
            }
            tmp /= 10;
        }
        if (n == count) {
            cout << cnt;
            break;
        }
        cnt++;
    }
    return 0;
}