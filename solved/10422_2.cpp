#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll d[5001][5001];
ll mod = 1000000007LL;

int main() {
    FAST_IO

    // dp 
    // d[N][L] : 괄호 문자열의 길이가 N이고 짝이 맞지 않는 '('의 개수가 L개라고 정의
    // 위의 정의에 따라 d[N][0]은 정답을 의미한다.
    // 정답의 경우의 수는 ')'로 끝나는 경우와 '('로 끝나는 경우 두가지가 있다.
    // 경우1) "~~~)"이 d[N][L]을 만족할 때, "~~~"부분은 d[N-1][L+1]이다.
    // 왜냐하면 길이가 1줄고 ')'는 "~~~"의 어딘가 '('와 결합될 것이므로 L+1이 된다.
    // 경우2) "~~~("이 d[N][L]을 만족할 때, "~~~"부분은 d[N-1][L-1]이다.
    // 왜냐하면 길이가 1줄고 '('이 1개 없어졌으므로 L-1이 된다.
    d[0][0] = 1;
    for (int i=1; i<=5000; i++) {
        for (int j=0; j<=i; j++) {
            d[i][j] = 0;
            if (j+1 <= i) d[i][j] += d[i-1][j+1];
            if (j-1 >= 0) d[i][j] += d[i-1][j-1];
            d[i][j] %= mod;
        }
    }

    // 입력 및 출력
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << d[n][0] << '\n';
    }
    return 0;
}