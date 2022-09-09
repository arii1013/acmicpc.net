#include <iostream>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

vector<int> a[32001];
int ind[32001];

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        ind[y] += 1;
    }

    // process & output
    priority_queue<int> q;
    for (int i=1; i<=n; i++) {
        if (ind[i] == 0) q.push(-i);
    }

    while (!q.empty()) {
        int x = -q.top(); q.pop();
        cout << x << ' ';

        for (int y : a[x]) {
            ind[y] -= 1;
            if (ind[y] == 0) q.push(-y);
        }
    }
    cout << '\n';

    return 0;
}