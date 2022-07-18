#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1001];
int d[1001];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    // dp d[i+j] = min(d[i+j], d[i]+1);
    memset(d, -1, sizeof(d));
    d[0] = 0;
    for (int i=0; i<n; i++) {
        if (d[i] == -1) continue;

        for (int j=1; j<=a[i]; j++) {
            if (i+j >= n) break;
            
            if (d[i+j] == -1 || d[i+j] > d[i]+1) d[i+j] = d[i]+1;
        }
    }

    // 출력
    cout << d[n-1] << '\n';
    return 0;
}