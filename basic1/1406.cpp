#include<iostream>
#include<list>
using namespace std;

int main() {
    string first;
    char order;
    int m;
    cin >> first >> m;
    list <char> l(first.begin(),first.end());
    auto cursor = l.end();

    for (int i = 0;i < m;i++) {
        cin >> order;
        switch (order) {
        case 'L':
            if (cursor != l.begin()) cursor--;
            break;
        case 'D':
            if (cursor != l.end()) cursor++;
            break;
        case 'B':
            if (cursor != l.begin()) {
                cursor = l.erase(--cursor); //list의 erase는 삭제한 원소의 다음 원소를 가리키는 iterator반환함
            }
            break;
        case 'P':
            char word;
            cin >> word;
            l.insert(cursor, word); //insert는 삽입한 원소를 가리키는 iterator반환함
            break;
        }
    }
    for (auto it = l.begin(); it != l.end(); it++) {
        printf("%c", *it);
    }
    return 0;
}