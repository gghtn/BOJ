//B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    string s;
    int b;
    cin >> s >> b;

    int result = 0, cnt = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= 'A') result += (s[i] - 'A' + 10) * pow(b, cnt);
        else result += (s[i]-'0') * pow(b, cnt);
        cnt++;
    }
    cout << result;

    return 0;
}