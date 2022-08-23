#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> v(n), ans(n,-1); //처음 수열을 저장할 v와 답을 저장할 ans
    stack<int> st;

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()] < v[i]){
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }

    return 0;
}