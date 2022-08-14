#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main() {
    FAST_IO

    // 입력
    ll n, m; cin >> n >> m;

    // 절대값
    // 부호 같은 경우 : 큰 수 - 작은 수
    // 부호가 다른 경우 : 큰 수(양수) - 작은 수(음수)
    if (n < m) swap(n, m);

    // 출력
    cout << n-m << '\n';
    return 0;
}