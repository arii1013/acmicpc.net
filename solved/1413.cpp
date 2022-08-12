#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll d[21][21];

// 최대공약수
ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    FAST_IO

    // 입력
    int n, m; cin >> n >> m;

    // dp : 제 1종 스털링 수
    // d[i][j] = d[i-1][j-1] + (i-1)*d[i-1][j];
    // d[i][j] : 길이가 i이고 사이클의 수가 j인 순열의 개수
    d[1][1] = 1;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            // d[i-1][j-1] : i번째 수가 혼자 사이클을 이루는 경우
            // (i-1)*d[i-1][j] : i번째 수가 기존 사이클에 포함되는 경우
            d[i][j] = d[i-1][j-1] + (i-1)*d[i-1][j];
        }
    }

    // 출력
    ll bunja = 0;
    for (int i=1; i<=m; i++) bunja += d[n][i];
    ll bunmo = 1;
    for (int i=1; i<=n; i++) bunmo *= i;
    ll g = gcd(bunja, bunmo);
    bunja /= g; bunmo /= g;
    cout << bunja << '/' << bunmo << '\n';
    return 0;
}