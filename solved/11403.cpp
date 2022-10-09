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
    int n; cin >> n;
    vector<vector<int>> d(n+1, vector<int>(n+1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin >> d[i][j];
    }

    // process
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (d[i][k] && d[k][j]) d[i][j] = 1;
            }
        }
    }

    // output
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << (d[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}