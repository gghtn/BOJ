#include<iostream>
using namespace std;

int main(){
    int t, h, w, n;
    int y, x;
    cin >> t;
    for(;t!=0;t--){
        cin >> h >> w >> n;
        if(n%h == 0) cout << h*100 + n/h << endl;
        else cout << (n%h)*100 + n/h + 1 << endl;
    }
    return 0;    
}
