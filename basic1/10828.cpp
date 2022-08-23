//c++의 경우 stack이 구현되어있기 때문에 stack을 이용하면 된다.
#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
void push(int x){
    st.push(x);
}
void pop(){
    if(!st.empty()){
        cout << st.top() <<endl;
        st.pop();
        }
    else 
        cout << "-1" << endl;
}
void size(){
    cout << st.size() << endl;
}
void empty(){
    cout << st.empty() <<endl;
}
void top(){
    if(!st.empty()) cout << st.top() <<endl;
    else cout << "-1" << endl;
}
int main(){
    int n, x;
    string order;
    cin >> n;
    for(;n!=0;n--){
        cin >> order;
        if(order == "push"){
            cin >> x;
            push(x);
        }
        else if(order == "pop") pop();
        else if(order == "size") size();
        else if(order == "empty") empty();
        else top();
    }
    return 0;
}