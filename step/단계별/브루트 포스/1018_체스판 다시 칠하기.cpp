/*
M×N 크기의 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다.따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다.
하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
using namespace std;

string chess[50];
string wb[8]{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string bw[8]{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int wb_compare(int n, int m) {
    int result = 0;
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < 8;j++) {
            if (wb[i][j] != chess[n+i][m+j]) result++;
        }
    }
    return result;
}
int bw_compare(int n, int m) {
    int result = 0;
    for (int i = 0;i < 8;i++) {
        for (int j = 0;j < 8;j++) {
            if (bw[i][j] != chess[n + i][m + j]) result++;
        }
    }
    return result;
}

int main() {
    int n, m, min = 64;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        cin >> chess[i];
    }
    for (int i = 0;i <= n - 8;i++) {
        for (int j = 0;j <= m - 8;j++) {
            if (wb_compare(i, j) < bw_compare(i, j)) {
                min = (wb_compare(i, j) < min) ? wb_compare(i, j) : min;
            }
            else {
                min = (bw_compare(i, j) < min) ? bw_compare(i, j) : min;
            }
        }
    }
    cout << min;

    return 0;
}