#include<iostream>
#include<stack>
using namespace std;

int main() {
    int total = 0;
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0;i < s.length();i++) {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')' && s[i - 1] == '(') {
            st.pop();
            total += st.size();
        }
        else {
            st.pop();
            total += 1;
        }
    }
    cout << total;
    return 0;
}