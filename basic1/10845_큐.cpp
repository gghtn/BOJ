#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue <int> q;
    int n;
    cin >> n;
    string order;

    for (;n != 0;n--) {
        cin >> order;
        if (order == "push") {
            int in;
            cin >> in;
            q.push(in);
        }
        else if (order == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (order == "size") {
            cout << q.size() << '\n';
        }
        else if (order == "empty") {
            cout << q.empty() << '\n';
        }
        else if (order == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (order == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}