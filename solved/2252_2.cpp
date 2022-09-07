#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

// sovled with dfs

vector<int> a[32001];
bool check[32001];

void go(int x) {
    check[x] = true;

    for (int y : a[x]) {
        if (check[y] == false) {
            go(y);
        }
    }

    cout << x << ' ';
}

int main() {
    FAST_IO

    // input && process && output
    int n, m; cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y; cin >> x >> y;
        a[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        if (check[i] == false) {
            go(i);
        }
    }
    cout << '\n';
    
    return 0;
}