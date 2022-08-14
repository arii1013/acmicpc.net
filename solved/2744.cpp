#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

char lower[26], upper[26];

bool isLower(char c) { return 'a' <= c && c <= 'z'; }

int main() {
    FAST_IO

    // 입력
    string s; cin >> s;

    for (int i=0; i<26; i++) {
        lower[i] = 'a'+i;
        upper[i] = 'A'+i;
    }

    // 출력
    for (auto x : s) cout << (isLower(x) ? upper[x-'a'] : lower[x-'A']);
    cout << '\n';
    return 0;
}