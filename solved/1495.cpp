#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int v[51];
bool d[51][1001];

int main() {
    FAST_IO

    // 입력
    int n, s, m;
    cin >> n >> s >> m;
    for (int i=1; i<=n; i++) cin >> v[i];

    // dp d[i][j] i번째 곡의 볼륨을 수정했을 때 볼륨 j로 조절이 가능한가
    // d[i][j] = d[i-1][j+-v[i]] (0 <= j+-v[i] <= m)
    d[0][s] = true;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (d[i-1][j]) {
                if (j+v[i] <= m) d[i][j+v[i]] = true;
                if (j-v[i] >= 0) d[i][j-v[i]] = true;
            }
        }
    }

    // 정답의 최대값 구하기, 정답이 없을 경우 -1
    int ans = -1;
    for (int j=0; j<=m; j++) {
        if (d[n][j]) ans = j;
    }
    
    // 출력
    cout << ans << '\n';
    return 0;
}