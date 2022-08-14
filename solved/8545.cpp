#include <iostream>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main() {
    FAST_IO

    // 입력
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    // 출력
    cout << s << '\n';
    return 0;
}