#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define max3(a, b, c) max(max(a, b), c)

int main() {
    FAST_IO

    // 입력
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }

    // dp d[i] = max(d[i-1][j], d[i][j-1], d[i-1][j-1]) + a[i][j]
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = max3(d[i-1][j], d[i][j-1], d[i-1][j-1]) + a[i][j];
        }
    }

    // 출력
    cout << d[n][m] << '\n';
    return 0;
}