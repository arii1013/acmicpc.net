#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll d[5001];
ll mod = 1000000007LL;

// dp d[n] : 길이가 n인 괄호 문자열의 최대 개수
// 괄호 문자열의 첫번째 값은 무조건 (이어야 한다. 아니면 구할 수 없다.
// 괄호 문자열의 첫번째 값과 쌍을 이룰 수 있는 위치 2*i를 정하면
// [1, i-1] 구간과 [i+1, n] 구간이 생성되고 각 구간의 길이는 i-2, n-i가 된다.
// 따라서 각 구간의 길이는 d[i-2], d[n-1]에서 구하고 없으면 메모이제이션을 실행한다.
ll go(int n) {
    if (n == 0) return 1;
    else if (d[n] >= 0) return d[n];

    d[n] = 0;
    for (int i=2; i<=n; i+=2) {
        d[n] += go(i-2) * go(n-i);
        d[n] %= mod;
    }
    return d[n];
} 

int main() {
    FAST_IO

    // 입력 및 출력
    memset(d, -1, sizeof(d));
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n%2 == 0) cout << go(n) << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}