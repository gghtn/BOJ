#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    string s;
    double op[26];
    stack<double> st;
    cin >> n >> s;

    for (int i = 0;i < n;i++) {
        cin >> op[i];
    }

    for (int i = 0;i < s.length();i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            st.push(op[s[i] - 'A']);
        }
        else {
            double a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            switch (s[i]) {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << st.top();
    return 0;
}