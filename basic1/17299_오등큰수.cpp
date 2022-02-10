#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), vnum(1000001), ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vnum[v[i]]++;
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && vnum[v[st.top()]] < vnum[v[i]]) {
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}