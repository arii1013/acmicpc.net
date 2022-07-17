#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    vector<pair<int, int>> a(n*2);
    for (int i=0; i<n; i++) {
        // 시작점과 끝점을 입력받음. 시작점은 1, 끝점은 -1로 구분하여 저장
        int st, ed; cin >> st >> ed;
        a[i*2] = make_pair(st, 1);
        a[i*2 + 1] = make_pair(ed, -1);
    }

    // 좌표값 오름차순, 끝점 우선 정렬
    sort(a.begin(), a.end());

    // 선의 총 길이 계산
    int ans = 0;
    int cnt = 0;
    int last = 0;
    for (auto &x : a) {
        // 겹치는 선이 없고 시작점이면, 시작점 기록
        if (cnt == 0 && x.second == 1) {
            last = x.first;
        }
        // 겹치는 선 계산
        cnt += x.second;
        // 겹치는 선이 없고 끝점이면, 선 길이 계산
        if (cnt == 0 && x.second == -1) {
            ans += x.first - last;
        }
    }

    // 출력
    cout << ans << '\n';
    return 0;
}