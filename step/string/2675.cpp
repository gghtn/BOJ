/*문자열을 입력받고 각 문자를 몇번 반복할지 입력받아 출력, 첫 수는 테스트 케이스의 개수*/
#include <iostream>
using namespace std;

int main(){
    int T, n; 
    string s;
    cin >> T;
    for(;T!=0;T--){
        cin >> n >> s;
        for(int i =0;i<s.length();i++){
            for(int j =0; j<n; j++){
                cout << s[i];
            }
        }
        cout << "\n";
    }
    return 0;    
}