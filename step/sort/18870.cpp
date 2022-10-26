#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, num;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    vector<int> copyV(v);
    sort(copyV.begin(), copyV.end());
    //중복 값 제거
    //unique 앞에서부터 중복되지 않는 값을 채워나가고 중복된 부분은 뒤로 밀린다. 이 때 중복되어 밀린 첫 원소의 주소를 리턴
    // 1, 1, 2, 3, 4, 4, 5  -> 1, 2, 3, 4, 5, <1>, 4        <1>의 주소 리턴
    copyV.erase(unique(copyV.begin(), copyV.end()), copyV.end());

    for (int i = 0; i < n; i++) {
        //lower_bound 처음 v[i]이상인 주소 반환
        cout << lower_bound(copyV.begin(), copyV.end(), v[i]) - copyV.begin() << ' ';
    }

    return 0;
}