#include <iostream>
#include <cstring>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int d[10001];

int main() {
    FAST_IO

    // dp
    // 1로 만드는 법, 1 = 1, 2 = 1 + 1, 3 = 1 + 1 + 1 ... 하나밖에 없다
    for (int i=0; i<=10000; i++) d[i] = 1;
    
    // 2로 만드는 법
    for (int i=0; i<=10000-2; i++) d[i+2] += d[i];

    // 3으로 만드는 법
    for (int i=0; i<=9997; i++) d[i+3] += d[i];

    // t개의 쿼리에 대한 출력
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}