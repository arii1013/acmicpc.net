#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

const int mod = 1000000007;
ll d[51][51][51][51];

// dp
int go(int n, int a, int b, int c) {
    // 곡을 하나도 녹음 안했을 때
    if (n == 0) {
        if (a == 0 && b == 0 && c == 0) return 1;
        return 0;
    }
    // 부른 횟수가 음수인 경우
    if (a < 0 || b < 0 || c < 0) return 0;
    // 메모이제이션
    ll &ans = d[n][a][b][c];
    if (ans != -1) return ans;
    ans = 0;

    // dp[n][a][b][c] = d[n-1][a-1][b][c] + d[n-1][a][b-1][c] + dp[n][a][b][c-1]
    //                  +dp[n-1][a-1][b-1][c] + dp[n][a-1][b][c-1]
    //                  +dp[n-1][a][b-1][c-1] + dp[n-1][a-1][b-1][c-1]
    // dp[n][a][b][c] : n번째 곡을 녹음했고, A는 a번, B는 b번, C는 c번 부른 경우의 수
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                if (i+j+k == 0) continue;
                ans += go(n-1, a-i, b-j, c-k);
            }
        }
    }

    ans %= mod;
    return ans;
}

int main() {
    FAST_IO

    // 입력
    int n, a, b, c; cin >> n >> a >> b >> c;
    
    // 출력
    memset(d, -1, sizeof(d));
    cout << go(n, a, b, c) << '\n';
    return 0;
}