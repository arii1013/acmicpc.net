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

    // dp d[i] = min(d[i], d[j]+1);
    memset(d, -1, sizeof(d));
    d[0] = 0;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (d[j] != -1 && i-j <= a[j]) {
                if (d[i] == -1 || d[i] > d[j]+1) {
                    d[i] = d[j]+1;
                }
            }
        }
    }

    // 출력
    cout << d[n-1] << '\n';
    return 0;
}