#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int i = 1;
    while (1) {
        if (N > i) {
            N -= i;
            i++;
        }
        else
            break;
    }

    if(i%2==1)
        cout << (i - N) + 1 << "/" << N;
    else
        cout << N << "/" << (i - N) + 1;

    return 0;
}
