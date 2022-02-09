#include<iostream>
#include<string>
#include<stack>
using namespace std;

void print(stack<char>& st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    string s;
    getline(cin, s);
    stack<char> st;

    for (int i = 0;i < s.length();i++) {
        if (s[i] == '<') {
            print(st);
            while (s[i] != '>') {
                cout << s[i];
                i++;
            }
            i--;
        }
        else if (s[i] == '>') cout << s[i];
        else if (s[i] == ' ') {
            print(st);
            cout << ' ';
        }
        else {
            st.push(s[i]);
        }
    }
    print(st);
    return 0;
}