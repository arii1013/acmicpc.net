#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

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
vector<Edge> a[20001];
ll dist[20001];
const ll inf = 123456789LL;
bool check[20001];

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    int start; cin >> start;
    for (int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        a[from].push_back(Edge{to, cost});
    }

    // process
    for (int i=1; i<=n; i++) dist[i] = inf;
    dist[start] = 0;
    priority_queue<pair<ll, int>> q;
    q.push(make_pair(0, start));

    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int x = p.second;
        if (check[x]) continue;
        check[x] = true;

        for (Edge e : a[x]) {
            if (dist[x] + e.cost < dist[e.to]) {
                dist[e.to] = dist[x] + e.cost;
                q.push(make_pair(-dist[e.to], e.to));
            }
        }
    }

    // output
    for (int i=1; i<=n; i++) {
        if (dist[i] >= inf) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}