#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int d[100001];
int w[101];
int v[101];

int main() {
    FAST_IO

    // 입력
    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> w[i] >> v[i];

    // dp d[i] = i번째까지 포함 여부를 생각해두었을 경우에 최대 가치
    // 1) i번째를 추가하는 경우: d[i-1][j-w[i]] (반드시 j-w[i] >= 0)
    // 2) i번째를 포함하지 않는 경우 : d[i-1][j]
    // 위 2가지 경우에서 더 큰 값이 최대값
    for (int i=1; i<=n; i++) {
        // dp 저장 공간을 공유하고 있으므로 j값은 내림차순으로 순회한다.
        // 이유) i는 1이고 w[i] = 1, j가 1->2로 오름차순으로 순회할 경우
        // d[1] = d[0]+v[1], d[2] = d[1]+v[1]
        // d[2]는 d[1]에서 최신화된 잘못된 메모이제이션을 참고함.
        for (int j=k; j>=1; j--) {
            if (j-w[i] >= 0) d[j] = max(d[j], d[j-w[i]] + v[i]);
        }
    }

    // 출력
    cout << d[k] << '\n';
    return 0;
}