#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

vector<int> a[10001];
int work[10001];
int ind[10001];
int d[10001];

int main() {
    FAST_IO

    // input
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> work[i];
        d[i] = work[i];

        int cnt; cin >> cnt;
        while (cnt--) {
            int x; cin >> x;
            a[x].push_back(i);
            ind[i] += 1;
        }
    }

    // process
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (ind[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        
        for (int y : a[x]) {
            ind[y] -= 1;
            if (d[y] < d[x] + work[y]) {
                d[y] = d[x] + work[y];
            }
            if (ind[y] == 0) {
                q.push(y);
            }
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }

    cout << ans << '\n';
    return 0;
}