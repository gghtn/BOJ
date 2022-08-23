/*
접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.
baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 이를
사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.
모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<string> v(n);
    for(int i=0; i<n;i++){
        v[i] = s.substr(i);
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        cout << v[i] <<'\n';
    }
    return 0;
}