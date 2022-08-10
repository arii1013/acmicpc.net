#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1000];
int d[1000];

char get_prev(char x) {
    if (x == 'B') return 'J';
    else if (x == 'O') return 'B';
    else if (x == 'J') return 'O';
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    string s; cin >> s;

    // dp
    // d[i] = d[j] + (i-j)*(i-j) (a[j] = prev(a[i]))
    // d[i] : i번째 도로까지의 최소 이동 비용
    // d[j] : j는 [1, i)의 구간을 만족할 때 j번째 도로까지의 최소 이동 비용
    memset(d, -1, sizeof(a));
    d[0] = 0;
    for (int i=1; i<n; i++) {
        char now = s[i];
        char prev = get_prev(now);

        for (int j=0; j<i; j++) {
            if (d[j] == -1) continue;
            if (s[j] != prev) continue;
            int cost = d[j] + (i-j)*(i-j);
            if (d[i] == -1 || d[i] > cost) d[i] = cost;
        }
    }

    // 출력
    cout << d[n-1] << '\n';
    return 0;
}