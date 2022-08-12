#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int d[301][301];

// dp
// d[i][j] = min(d[k][j]+d[i-k][j]+1, d[i][k]+d[i][j-k]+1)
// d[i][j] = ixj 크기의 초콜렛을 1x1 크기로 최소로 자르는 횟수
int go(int i, int j) {
    // 쪼갤 수 없는 경우
    if (i == 1 && j == 1) return 0;
    // 메모이제이션
    int &ans = d[i][j];
    if (ans != -1) return ans;
    ans = 2147483647;

    // d[i][M]+d[n-i][M]+1 : 가로로 쪼개는 경우
    for (int k=1; k<i; k++) {
        int t1 = go(k, j);
        int t2 = go(i-k, j);
        if (ans > t1 + t2 + 1) ans = t1 + t2 + 1;
    }

    // d[N][i]+d[N][M-i]+1 : 세로로 쪼개는 경우
    for (int k=1; k<j; k++) {
        int t1 = go(i, k);
        int t2 = go(i, j-k);
        if (ans > t1 + t2 + 1) ans = t1 + t2 + 1;
    }
    
    return ans;
}

int main() {
    FAST_IO

    // 입력
    int n, m; cin >> n >> m;

    // 출력
    memset(d, -1, sizeof(d));
    cout << go(n, m) << '\n';
    return 0;
}