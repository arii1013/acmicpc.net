#include <iostream>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[101];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    int m; cin >> m;

    // 출력
    sort(a, a+n);
    int ans = upper_bound(a, a+n, m) - lower_bound(a, a+n, m);
    cout << ans << '\n';
    return 0;
}