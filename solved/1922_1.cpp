#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Edge {
    int to;
    int cost;
    bool operator < (const Edge &other) const {
        return cost > other.cost;
    }
};
vector<Edge> a[1001];
bool c[1001];

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        a[from].push_back(Edge({to, cost}));        
        a[to].push_back(Edge({from, cost}));
    }

    // process
    c[1] = true;
    priority_queue<Edge> q;
    for (Edge e : a[1]) q.push(e);

    int ans = 0;
    while (!q.empty()) {
        Edge e = q.top(); q.pop();
        if (c[e.to] == true) continue;
        c[e.to] = true;

        ans += e.cost;
        int x = e.to;
        for (Edge ee : a[x]) q.push(ee);
    }

    // output
    cout << ans << '\n';
    return 0;
}