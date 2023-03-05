#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define ll long long

ll INF = 100000LL * 100000LL + 1LL;
struct Edge {
    int from;
    int to;
    ll distance;

    Edge(int a, int b, ll t) {
        from = a;
        to = b;
        distance = t;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    int n, m;
    cin >> n >> m;

    vector<int> disable(n, 0); // 상대방의 포탑 시야 안에 있는 노드 정보 vector
    for (int i=0; i<n; i++) {
        cin >> disable[i];
    }
    vector<vector<Edge>> edges(n); // 간선 정보를 저장할 vector
    for (int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;

        edges[a].push_back(Edge(a, b, t));
        edges[b].push_back(Edge(b, a, t));
    }
    vector<ll> distance(n, INF); // 거리를 저장할 vector

    // process
    int start = 0, end = n-1;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, start));
    distance[start] = 0;

    while (!pq.empty()) {
        auto x = pq.top();
        ll curDist = -x.first;
        int curNode = x.second;
        pq.pop();
        if (curDist > distance[curNode]) {
            continue;
        }

        for (Edge edge : edges[curNode]) {
            int nextNode = edge.to;
            ll nextDist = curDist + edge.distance;
            // 방문할 노드가 상대방의 시야에 있는 노드일 경우 continue
            if (nextNode != end && disable[nextNode]) {
                continue;
            }

            if (nextDist < distance[nextNode]) {
                pq.push(make_pair(-nextDist, nextNode));
                distance[nextNode] = nextDist;
            }   
        }
    }
 
    // output
    if (distance[n-1] != INF) {
        cout << distance[n-1] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}