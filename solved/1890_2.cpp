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
    // d[i+a[i][j]][j] += d[i][j] (i+a[i][j] < n)
    // d[i][j+a[i][j]] += d[i][j] (j+a[i][j] < n)
    d[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            // 이동할 수 있는 칸의 개수가 0이면 제외
            if (a[i][j] == 0) continue;

            // x축으로 이동할 수 있는 경우
            if (i + a[i][j] < n) d[i+a[i][j]][j] += d[i][j];

            // y축으로 이동할 수 있는 경우
            if (j + a[i][j] < n) d[i][j + a[i][j]] += d[i][j];
        }
    }

    // 출력
    cout << d[n-1][n-1] << '\n';
    return 0;
}