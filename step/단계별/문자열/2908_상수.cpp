/*두 수가 주어졌을 때(두수는 세자리 수이며 0이포함되어 있지 않음) 이 수를 거꾸로
읽었을 때 큰 값을 거꾸로 바꿔서 출력하라*/

/* reverse함수를 사용했을 때
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    if(stoi(s1) > stoi(s2)) cout<<s1;
    else cout << s2;

    return 0;
}
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    char tmp;
    cin >> s1 >> s2;
    tmp = s1[0];
    s1[0] = s1[2];
    s1[2] = tmp;

    tmp = s2[0];
    s2[0] = s2[2];
    s2[2] = tmp;

    if (s1 > s2) cout << s1;
    else cout << s2;

    return 0;
}