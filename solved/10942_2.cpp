#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[2000];
bool d[2000][2000];

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    // dp (bottom-up)
    // [i, j] 구간의 원소 개수가 1개, 항상 팰린드롬을 만족함.
    for (int i=0; i<n; i++) d[i][i] = true;

    // [i, j] 구간의 원소 개수가 2개
    for (int i=0; i<n-1; i++) {
        if (a[i] == a[i+1]) d[i][i+1] = true;
    }

    // [i, j] 구간의 원소 개수가 k개
    for (int k=3; k<=n; k++) {
        for (int i=0; i<=n-k; i++) {
            int j = i+k-1;
            // 양 끝이 같은 문자고, 그 안의 내용도 팰린드롬을 만족한다면
            if (a[i] == a[j] && d[i+1][j-1]) d[i][j] = true;
        }
    }

    // m개의 쿼리에 대한 출력
    int m; cin >> m;
    while (m--) {
        int s, e; cin >> s >> e;
        cout << (d[s-1][e-1] ? 1 : 0) << '\n';
    }
    return 0;
}