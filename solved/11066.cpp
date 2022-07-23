#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[501];
int d[501][501];

int go(int i, int j) {
    // 합칠 종이가 1장인 경우, 합칠 필요가 없다.
    if (i == j) return 0;

    // 이미 최소값을 구한 경우
    if (d[i][j] != -1) return d[i][j];

    // [i, j] 구간의 합
    int sum = 0;
    for (int k=i; k<=j; k++) sum += a[k];

    // d[i][j] = min(d[i][k]) + min(d[k+1][j]) + sum
    int &ans = d[i][j];
    for (int k=i; k<=j-1; k++) {
        int temp = go(i, k) + go(k+1, j) + sum;
        if (ans == -1 || ans > temp) ans = temp;
    }
    return ans;
}

int main() {
    FAST_IO

    // 입력 및 출력
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        memset(d, -1, sizeof(d));
        cout << go(1, n) << '\n';
    }
    return 0;
}