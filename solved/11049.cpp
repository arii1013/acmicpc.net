#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1000][2];
int d[1000][1000];

// dp
// d[i][j] = min(d[i][j], d[i][k]+d[k+1][j]+a[i][0]*a[k][1]*a[y][1])
// d[i][j] : [i, j] 구간의 행렬을 곱하는데 연산의 최솟값
// 행렬이 4개가 있을 경우 다음과 같이 2분할하여 구한다.
// (1, 2) | (2, 3) (3, 4) (4, 5)
// (1, 2) (2, 3) | (3, 4) (4, 5)
// (1, 2) (2, 3) (3, 4) | (4, 5)
int go(int x, int y) {
    // 메모이제이션
    if (d[x][y]) return d[x][y];
    // [x, x] 구간인 경우
    if (x == y) return 0;
    // [x, x+1] 구간인 경우
    if (x+1 == y) return a[x][0]*a[x][1]*a[x+1][1];

    int &ans = d[x][y];
    ans = -1;
    for (int k=x; k<=y-1; k++) {
        int t1 = go(x, k);
        int t2 = go(k+1, y);
        if (ans == -1 || ans > t1+t2+a[x][0]*a[k][1]*a[y][1]) {
            ans = t1+t2+a[x][0]*a[k][1]*a[y][1];
        }
    }

    return ans;
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i][0] >> a[i][1];

    // 출력
    cout << go(0, n-1) << '\n';
    return 0;
}