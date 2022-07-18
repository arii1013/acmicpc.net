#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int t[1500000+50];
int p[1500000];
int d[1500000];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> t[i] >> p[i];

    // dp
    // 상담을 하면: d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
    // 상담을 안 하면: d[i+1] = max(d[i], d[i+1]);
    for (int i=0; i<n; i++) {
        d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
        d[i+1] = max(d[i+1], d[i]);
    }

    // 출력
    cout << d[n] << '\n';
    return 0;
}