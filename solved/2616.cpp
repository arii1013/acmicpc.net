#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int s[50001];
int a[50001];
int d[50001][4];

int sum(int x, int y) { return s[y] - s[x-1]; }

int main() {
    FAST_IO

    // 입력 및 부분합 구하기
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int m; cin >> m;

    // dp
    // d[i][j] = max(d[i-1][j], d[i-m][j-1] + sum(i-m+1, i))
    // d[i][j] : i번째 객차까지 있을 때 j개의 소형 기관차로 이동한 최대 사람 수
    for (int j=1; j<=3; j++) {
        // 소형 기관차는 최소 m개의 객차를 옮겨야 하므로 m, 2m, 3m부터의 정보만 필요
        for (int i=m*j; i<=n; i++) {
            // max(d[i-1][j], d[i-m][j-1] + sum(i-m+1, i))
            // d[i-1][j] : (i-m, i] 구간(최우측)의 열차를 끌지 않을 경우
            // d[i-m][j-1] + sum(i-m+1, i) : (i-m, i] 구간(최우측)의 열차를 끌 경우
            d[i][j] = d[i-1][j];
            d[i][j] = max(d[i][j], d[i-m][j-1] + sum(i-m+1, i));
        }
    }

    // 출력
    cout << d[n][3] << '\n';
    return 0;
}