#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int n, m;
int a[1000];
int d[1000][1000];

// dp
// d[idx][cnt] = min(d[idx+1][a[idx]+1] + cost, d[idx+1][cnt+a[idx]+1])
// d[idx][cnt] : idx번째 이름을 적었고 현재 줄의 cnt번째 위치에 커서가 위치
int go(int idx, int cnt) {
    // n개의 이름을 적은 경우
    if (idx == n) return 0;

    // 메모이제이션
    int &ans = d[idx][cnt];
    if (ans != -1) return ans;

    // d[idx+1][a[idx]+1] + cost
    // 다음 줄로 넘어가는 경우
    int space = m-(cnt-1);
    int cost = space*space;
    ans = go(idx+1, a[idx]+1) + cost;

    // d[idx+1][cnt+a[idx]+1]
    // 이번 줄에 쓰는 경우
    if (cnt + a[idx] <= m) {
        int cur = go(idx+1, cnt+a[idx]+1);
        if (ans > cur) ans = cur;
    }

    return ans;
}   

int main() {
    FAST_IO

    // 입력
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];

    // 출력
    memset(d, -1, sizeof(d));
    cout << go(1, a[0]+1) << '\n';
    return 0;
}