/*
어떤 사람의 몸무게가 x kg이고 키가 y cm라면 이 사람의 덩치는 (x, y)로 표시된다.
두 사람 A 와 B의 덩치가 각각 (x, y), (p, q)라고 할 때 x > p 그리고 y > q 이라면 우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다.
N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다. 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다.
이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다.
*/
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* kg = new int[n];   //pair사용-> pair<int,int>arr[50];
    int* cm = new int[n];
    int* rank = new int[n] {};
    for (int i = 0; i < n;i++) {
        cin >> kg[i] >> cm[i];  //pair사용-> cin >> arr[i].first >> arr[i].second;
    }

    for (int j = 0;j < n;j++) {
        for (int k = 0;k < n;k++) {
            if (kg[k] > kg[j] && cm[k] > cm[j]) rank[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << rank[i] + 1;
        if (i == n - 1) break;
        cout << " ";
    }
    return 0;
}
