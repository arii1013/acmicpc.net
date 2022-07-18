#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};

int main() {
    FAST_IO

    // 입력
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) cin >> a[i][j];
    }

    // dp d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j];
    vector<vector<int>> d(n+1, vector<int>(m+1, 0));
    d[1][1] = a[1][1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            d[i][j] = max(d[i-1][j], d[i][j-1]) + a[i][j];
        }
    }

    // 출력
    cout << d[n][m] << '\n';
    return 0;
}