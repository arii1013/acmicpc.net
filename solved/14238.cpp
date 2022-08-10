#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

bool d[51][51][51][3][3];
char ans[52];
int n;
int cnt[3];

// dp
// d[i][a][b][p1][p2] : 문자열의 길이가 i이고 A의 개수가 a개 B의 개수가 b개 이전 문자열이 p1, 전전 문자열이 p2인 경우
bool go(int i, int a, int b, int p1, int p2) {
    // i번째 문자까지 정한 경우
    if (i == n) {
        // A, B, C 각 문자의 개수가 일치하면 정답
        if (a == cnt[0] && b == cnt[1] && i-a-b == cnt[2]) return true;
        return false;
    }
    // 메모이제이션
    if (d[i][a][b][p1][p2]) return false;
    d[i][a][b][p1][p2] = true;

    // i번째 날 A가 출근한 경우
    if (a+1 <= cnt[0]) {
        ans[i] = 'A';
        if (go(i+1, a+1, b, 0, p1)) return true;    
    }

    // i번째 날 B가 출근한 경우
    if (b+1 <= cnt[1] && p1 != 1) {
        ans[i] = 'B';
        if (go(i+1, a, b+1, 1, p1)) return true;
    }

    // i번째 날 C가 출근한 경우
    if (i+1-a-b <= cnt[2] && p1 != 2 && p2 != 2) {
        ans[i] = 'C';
        if (go(i+1, a, b, 2, p1)) return true;
    }

    return false;
}

int main() {
    FAST_IO

    // 입력
    string s; cin >> s;
    n = s.size();
    for (auto x : s) cnt[x-'A']++;
    // 출력
    if (go(0, 0, 0, 'A', 'A')) cout << ans << '\n';
    else cout << -1 << '\n';
    return 0;
}