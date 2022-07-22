#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int d[101][100001];
int w[101];
int v[101];

int main() {
    FAST_IO

    // 입력
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];

    // dp
    // 1) i번째를 추가하는 경우: d[i][j] = d[i-1][j-w[i]] (반드시 j-w[i] >= 0)
    // 2) i번째를 포함하지 않는 경우 : d[i][j] = d[i-1][j]
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            d[i][j] = d[i-1][j];
            if (j-w[i] >= 0) d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);
        }
    }

    // 출력
    cout << d[n][k] << '\n';
    return 0;
}