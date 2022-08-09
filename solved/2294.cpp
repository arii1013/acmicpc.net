#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[100];
int d[10001];

int main() {
    FAST_IO

    // 입력받고 동전의 가치가 오름차순이 되도록 정렬
    int n, k; cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    // dp:
    // a[i] = i번째 동전의 가치
    // d[j] = 가치가 j가 되도록 만드는 최소 방법
    memset(d, -1, sizeof(d));
    d[0] = 0;
    // 동전 여러개로 만들 수 있는 경우를 모두 입력
    for (int i=0; i<n; i++) {
        for (int j=0; j+a[i]<=k; j++) {
            // 만들 수 없는 경우
            if (d[j] == -1) continue;
            
            // 만들 수 있는 경우
            if (d[j+a[i]] == -1 || d[j]+1 < d[j+a[i]]) {
                d[j+a[i]] = d[j]+1;
            }
        }
    }

    // 출력
    cout << d[k] << '\n';
    return 0;
}