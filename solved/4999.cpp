#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

bool a[31];

int main() {
    FAST_IO

    // 입력
    for (int i=0; i<28; i++) {
        int n; cin >> n;
        a[n] = true;
    }

    // 출력
    for (int i=1; i<=30; i++) {
        if (!a[i]) cout << i << '\n';
    }
    return 0;
}