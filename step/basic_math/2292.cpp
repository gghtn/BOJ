#include <iostream>
using namespace std;

int main(){
    int N, prev = 1, count = 1;
    cin >> N;
    int i = 1;
    while(1){
        if(prev < N){
            prev += 6*i;
            count++;
            i++;
        }
        else
            break;
    }
    cout << count;

    return 0;
}
