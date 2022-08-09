#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[100][100];
ll d[100][100];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    // dp
    // d[i][j] = d[i-k][j] + d[i][j-k]
    d[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // (0, 0)인 경우 제외
            if (i == 0 && j == 0) continue;

            // (k+a[k][j], j) -> (i, j)인 경우
            for (int k=0; k<i; k++) {
                if (k + a[k][j] == i) {
                    d[i][j] += d[k][j];
                }
            }

            // (i, k+a[i][k]) -> (i, j)인 경우
            for (int k=0; k<j; k++) {
                if (k + a[i][k] == j) {
                    d[i][j] += d[i][k];
                }
            }
        }
    }

    // 출력
    cout << d[n-1][n-1] << '\n';
    return 0;
}