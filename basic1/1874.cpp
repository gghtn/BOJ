/*
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지,
있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    vector<char> result;
    stack<int> st;
    int n, i = 1, sequence;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> sequence;
        while (sequence >= i) {
            st.push(i);
            i++;
            result.push_back('+');
        }
        if (st.top() == sequence) {
            st.pop();
            result.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    for (int k = 0; k < result.size(); k++) {
        cout << result[k] <<"\n";       //endl의 경우 시간초과가 나옴
    }
    return 0;
}