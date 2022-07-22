#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int d[61][61][61];

// dp (top-down)
int go(int i, int j, int k) {
    // i, j, k가 음수일 경우
    if (i < 0) return go(0, j, k);
    if (j < 0) return go(i, 0, k);
    if (k < 0) return go(i, j, 0);
    // i, j, k가 모두 0이면 (=SCV를 모두 죽였을 경우)
    if (i == 0 && j == 0 && k == 0) return 0;

    // 메모이제이션을 이미 수행한 경우 그냥 리턴
    int &ans = d[i][j][k];
    if (ans != -1) return ans;
    ans = 2147483647;

    // 순열을 통해 모든 경우의 수 dp
    vector<int> p = {1, 3, 9};
    do {
        auto tmp = go(i-p[0], j-p[1], k-p[2]);
        if (tmp < ans) ans = tmp;
    } while (next_permutation(p.begin(), p.end()));
    ans += 1;
    return ans;
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    int scv[3] = {0, 0, 0};
    for (int i=0; i<n; i++) cin >> scv[i];

    // dp
    memset(d, -1, sizeof(d));
    cout << go(scv[0], scv[1], scv[2]) << '\n';
    return 0;
}