#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 123456789

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    for (int i=0; i<=n; i++) d[i][i] = 0;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        d[u][v] = d[v][u] = 1;
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
    int idx = 0;
    int value = INF;
    for (int i=1; i<=n; i++) {
        int temp = 0;
        for (int j=1; j<=n; j++) temp += d[i][j];

        if (temp < value) {
            value = temp;
            idx = i;
        }
    }
    cout << idx << '\n';
    return 0;
}