#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define ll long long
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct Edge {
    int from;
    int to;
    int cost;
};

int main() {
    FAST_IO

    int t; cin >> t;
    while (t--) {
        // input
        int n, m, w;
        cin >> n >> m >> w;
        vector<Edge> a;
        for (int i=0; i<m; i++) {
            Edge x;
            cin >> x.from >> x.to >> x.cost;
            a.push_back(x);
            swap(x.from, x.to);
            a.push_back(x);
        }
        for (int i=0; i<w; i++) {
            Edge x;
            cin >> x.from >> x.to >> x.cost;
            x.cost = -x.cost;
            a.push_back(x);
        }

        // process
        ll inf = 123456789LL;
        vector<ll> d(n+1, 0);
        bool negative_cycle = false;
        
        for (int i=1; i<=n; i++) {
            for (int j=0; j<a.size(); j++) {
                int x = a[j].from;
                int y = a[j].to;
                int z = a[j].cost;

                if (d[x] != inf && d[y] > d[x]+z) {
                    d[y] = d[x]+z;
                    if (i == n) {
                        negative_cycle = true;
                    }
                }
            }
        }

        // output
        if (negative_cycle) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}