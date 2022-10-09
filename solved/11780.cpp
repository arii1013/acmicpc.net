#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
const int INF = 123456789;

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n+1, vector<int>(n+1, INF));
    for (int i=1; i<=n; i++) d[i][i] = 0;
    for (int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (d[from][to] > cost) {
            d[from][to] = cost;
        }
    }
    vector<vector<vector<int>>> trace(n+1, vector<vector<int>>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j || d[i][j] >= INF) continue;
            trace[i][j].push_back(i);
            trace[i][j].push_back(j);
        }
    }

    // process
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    // while (!trace[i][j].empty() && trace[i][j].back() == i) trace[i][j].pop_back();
                    trace[i][j] = trace[i][k];
                    for (int t=1; t<trace[k][j].size(); t++) {
                        trace[i][j].push_back(trace[k][j][t]);
                    }
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
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << trace[i][j].size() << ' ';
            for (int x : trace[i][j]) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}