#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

const ll mod = 100000;
ll d[200][200];
char open[5] = "({[";
char close[5] = ")}]";
string s;

// dp
// d[i][j] = sum(d[i+1][k-1] * d[k+1][j]) (i < k <= j, k += 2)
// d[i][j] : [i, j] 구간의 괄호 문자열의 개수
ll go(int i, int j) {
    // 괄호 문자열 () {} []을 찾은 경우
    if (i > j) return 1;
    // 메모이제이션
    ll &ans = d[i][j];
    if (ans != -1) return ans;
    ans = 0;

    // sum(d[i+1][k-1] * d[k+1][j]) (i < k <= j, k += 2)
    // (i, j] 구간을 만족하는 정수 k와 i번의 괄호가 괄호 문자열을 만족한다면
    // d[i+1][k-1] * d[k+1][j]는 i와,k가 괄호 문자열을 이루는 d[i][j] 괄호 문자열의 일부분이다.
    for (int k=i+1; k<=j; k+=2) {
        for (int l=0; l<3; l++) {
            if (s[i] == open[l] || s[i] == '?') {
                if (s[k] == close[l] || s[k] == '?') {
                    ll temp = go(i+1, k-1) * go(k+1, j);
                    ans += temp;
                    if (ans >= mod) ans = mod + ans % mod;
                }
            }
        }
    }
    return ans;
}

int main() {
    FAST_IO
    
    // 입력
    int n; cin >> n;
    cin >> s;

    // 출력
    memset(d, -1, sizeof(d));
    ll ans = go(0, n-1);
    if (ans >= mod) cout << setw(5) << setfill('0') << ans%mod << '\n';
    else cout << ans << '\n';
    return 0;
}