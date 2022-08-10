#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

bool d[31][31][31][436];
char ans[32];
int n, k;

// dp
// d[i][a][b][p] : 길이가 i이고 A의 개수가 a, B의 개수가 b, S[i] < S[j]를 만족하는 쌍의 개수가 p개
int go(int i, int a, int b, int p) {
    // n개의 문자에 대하여 모든 경우의 수를 구한 경우
    if (i == n) {
        if (p == k) return true;
        return false;
    }
    // 메모이제이션
    if (d[i][a][b][p]) return false;
    d[i][a][b][p] = true;

    // i번째 문자를 A로 정한 경우
    ans[i] = 'A';
    if (go(i+1, a+1, b, p)) return true;

    // i번째 문자를 B로 정한 경우
    ans[i] = 'B';
    if (go(i+1, a, b+1, p+a)) return true;

    // i번째 문자를 C로 정한 경우
    ans[i] = 'C';
    if (go(i+1, a, b, p+a+b)) return true;

    return false;
}

int main() {
    FAST_IO

    // 입력
    cin >> n >> k;

    // 출력
    if (go(0, 0, 0, 0)) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}