#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int n, m;
int a[10];
bool d[5001][5001];

// dp
// d[i][j] -> d[i+j+a[k]][j+a[k]]
// d[i][j] : 팔굽혀펴기를 i번 했고 현재 스코어가 j
void go(int i, int j) {
    // 팔굽혀펴기 횟수를 충족한 경우
    if (i > n) return;
    // 메모이제이션
    if (d[i][j]) return;
    d[i][j] = true;

    // d[i+j+a[k]][j+a[k]]
    // 다음 팔굽혀펴기 총 횟수가 i+j+a[k], 스코어가 j+a[k]
    for (int k=0; k<m; k++) go(i+j+a[k], j+a[k]);
}


int main() {
    FAST_IO

    // case
    int t; cin >> t;
    while (t--) {
        // 입력
        cin >> n >> m;
        for (int i=0; i<m; i++) cin >> a[i];

        // dp
        memset(d, false, sizeof(d));
        go(0, 0);

        // 출력
        int ans = -1;
        for (int j=0; j<=5000; j++) {
            if (d[n][j]) ans = j;
        }
        cout << ans << '\n';
    }

    return 0;
}