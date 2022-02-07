/*
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 
 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내야 한다.
*/
#include<iostream>
using namespace std;

int main(){
    int t;
    string ps;
    cin >> t;
    while(t){
        int left=0, right=0;
        cin >> ps;
        for(int i=0;i<ps.length();i++){
            if(ps[i] == '(') left++;
            else if(ps[i]==')') right++;

            if(right > left){
                cout << "NO" <<endl;
                break;
            }
        }
        if(right == left) cout << "YES" <<endl;
        t--;
    }
    return 0;
}