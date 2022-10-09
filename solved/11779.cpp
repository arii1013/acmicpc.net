#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
#define LL long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Edge {
    int to;
    int cost;
    Edge (int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[1001];
bool c[1001];
int dist[1001];
int v[1001];
int inf = 123456789;

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        a[from].push_back(Edge(to, cost));
    }
    int start, end; cin >> start >> end;

    for (int i=1; i<=n; i++) dist[i] = inf;
    dist[start] = 0;
    v[start] = -1;

    for (int k=0; k<n-1; k++) {
        int m = inf+1;
        int x = -1;
        for (int i=1; i<=n; i++) {
            if (c[i] == false && dist[i] < m) {
                m = dist[i];
                x = i;
            }
        }

        c[x] = true;
        for (Edge e : a[x]) {
            if (dist[e.to] > dist[x] + e.cost) {
                dist[e.to] = dist[x] + e.cost;
                v[e.to] = x;
            }
        }
    }

    cout << dist[end] << '\n';
    stack<int> st;
    int x = end;
    while (x != -1) {
        st.push(x);
        x = v[x];
    }
    cout << st.size() << '\n';
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
    return 0;
}