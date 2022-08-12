#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1000];
int d[1000][1000];

// dp
// d[i][j] = max(d[i+1][j], d[i+1][k-1] + d[k+1][j] + 1)
// d[i][j] : i번째 사람 부터 j번째 사람까지 최대 몇 쌍이 건배를 할 수 있는가
int go(int i, int j) {
    // 예외 처리
    if (i >= j) return 0;
    // 메모이제이션
    int &ans = d[i][j];
    if (ans != -1) return ans;
    // d[i+1][j] : i번째 사람이 건배를 하지 않는 경우
    ans = go(i+1, j);

    // d[i+1][k-1] + d[k+1][j] + 1
    // k는 (i, j] 구간이고 a[i]와 a[k]가 건배를 할 수 있다면
    // [i+1, k-1]그룹과 [k+1, j]그룹과 (a, k)그룹 세 그룹의 최대 건배쌍을 구한다.
    for (int k=i+1; k<=j; k++) {
        int cur = 0;
        if (a[i] == a[k]) cur = go(i+1, k-1) + go(k+1, j) + 1;
        if (ans < cur) ans = cur;
    }
    
    return ans;
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    // 출력
    memset(d, -1, sizeof(d));
    cout << go(0, n-1) << '\n';
    return 0;
}