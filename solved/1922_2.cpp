#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Edge {
    int from;
    int to;
    int cost;
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};
int p[10001];

int Find(int x) {
    if (x == p[x]) return x;
    else return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    vector<Edge> a(m);
    for (int i=0; i<m; i++) {
        cin >> a[i].from >> a[i].to >> a[i].cost;
    }
    sort(a.begin(), a.end());
    for (int i=1; i<=n; i++) p[i] = i;

    // process
    int ans = 0;
    for (int i=0; i<m; i++) {
        Edge e = a[i];
        int x = Find(e.from);
        int y = Find(e.to);
        if (x == y) continue;

        Union(x, y);
        ans += e.cost;
    }

    // output
    cout << ans << '\n';
    return 0;
}