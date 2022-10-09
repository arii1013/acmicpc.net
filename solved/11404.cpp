#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    FAST_IO

    // input
    const int INF = 123456789;
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    for (int i=1; i<=n; i++) d[i][i] = 0;
    for (int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (d[from][to] > cost) d[from][to] = cost;
    }

    // process
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // output
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << (d[i][j] >= INF ? 0 : d[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}