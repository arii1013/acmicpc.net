#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1001][1001];
int d[1001][1001];

// dp d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j] (top-down);
int go(int i, int j) {
    if (i < 1 || j < 1) return 0;
    if (d[i][j] >= 0) return d[i][j];

    d[i][j] = max(go(i-1, j), go(i, j-1)) + a[i][j];

    return d[i][j];
}

int main() {
    FAST_IO

    // 입력
    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }

    // dp d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j] (top-down);
    memset(d, -1, sizeof(d));
    go(n, m);

    // 출력
    cout << d[n][m] << '\n';
    return 0;
}