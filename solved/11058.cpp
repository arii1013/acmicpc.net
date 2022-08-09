#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

ll d[100+1];

int main() {
    FAST_IO

    // 입력 및 초기화
    int n; cin >> n;
    for (int i=0; i<=n; i++) d[i] = i;

    // d[i] : i번 눌렀을 때 최대값
    // A를 누른 경우: d[i] = d[i-1] + 1
    // 선택 & 복사 & 붙혀넣기 한 경우 : d[i] = d[i-3]*2
    // 붙혀 넣기를 연속으로 한 경우 : d[i] = d[i-4]*3 or d[i-5]*4 or d[i-6]*5 or ...
    for (int i=1; i<=n; i++) {
        d[i] = d[i-1] + 1;
        for (int j=1; j<=i-3; j++) {
            ll cur = d[i-j-2] * (j+1);
            if (cur > d[i]) d[i] = cur;
        }
    }

    // 출력
    cout << d[n] << '\n';
    return 0;
}