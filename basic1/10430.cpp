/*
(A+B)%C는 ((A%C) + (B%C))%C 와 같을까?

(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?

세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.
*/
#include<iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << '\n' << ((A % C) + (B % C)) % C << '\n'
        << (A * B) % C << '\n' << ((A % C) * (B % C)) % C;
    return 0;
}