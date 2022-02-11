//중위 표기식을 후위 표기식으로 바꾸는 프로그램
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    string mid;
    cin >> mid;
    stack<char> st;

    for (int i = 0; i < mid.length(); i++) {
        if ('A' <= mid[i] && mid[i] <= 'Z') cout << mid[i];
        else {
            switch (mid[i]) {
            case '(':
                st.push(mid[i]);
                break;
            case '*':
            case '/':
                if(!st.empty() && (st.top() == '*' || st.top() == '/')) {
                    cout << st.top();
                    st.pop();
                }
                st.push(mid[i]);
                break;
            case '+':
            case '-':
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.push(mid[i]);
                break;
            case ')':
                while (!st.empty() && st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
                break;
            }
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
    return 0;
}