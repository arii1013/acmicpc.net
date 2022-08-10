#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[100];
ll d[100][21];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n; n--;
    for (int i=0; i<n; i++) cin >> a[i];
    int goal; cin >> goal;

    // dp
    // d[i][j] += d[i-1][j+a[i]] + d[i-1][j-a[i]] (j+a[i] <= 20, j-a[i] >= 0)
    // d[i][j] : i번째 수까지 사용해서 j를 만들 수 있는 경우의 수
    // d[i-1][j+a[i]] : i-1번째 수까지 사용해서 j+a[i]를 만든 경우, 즉 i번째 수를 뺀 경우
    // d[i-1][j-a[i]] : i-1번째 수까지 사용해서 j-a[i]를 만든 경우, 즉 i번째 수를 더한 경우
    d[0][a[0]] = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<=20; j++) {
            if (j-a[i] >= 0) d[i][j] += d[i-1][j-a[i]];
            if (j+a[i] <= 20) d[i][j] += d[i-1][j+a[i]];
        }
    }

    // 출력
    cout << d[n-1][goal] << '\n';
    return 0;
}