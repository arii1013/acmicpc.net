#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define LL long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) :
        to(to), cost(cost) {}
};
vector<Edge> a[1001];
int dist[1001];
bool check[1001];
const int inf = 123456789;

int main() {
    FAST_IO

    // input
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y, z));
    }

    int start, end; cin >> start >> end;
    for (int i=1; i<=n; i++) dist[i] = inf;
    dist[start] = 0;

    for (int k=0; k<n-1; k++) {
        int m = inf+1;
        int x = -1;

        for (int i=1; i<=n; i++) {
            if (check[i] == false && m > dist[i]) {
                m = dist[i];
                x = i;
            }
        }
        check[x] = true;
        for (int i=0; i<a[x].size(); i++) {
            int y = a[x][i].to;
            if (dist[y] > dist[x]+a[x][i].cost) {
                dist[y] = dist[x]+a[x][i].cost;
            }
        }
    }

    // output
    cout << dist[end] << '\n';
    return 0;
}