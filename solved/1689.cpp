#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using Point = pair<int, int>;

int main() {
    FAST_IO

    // 시작점과 끝점을 입력받고, 시작은 1 끝점은 -1로 벡터에 저장
    int n; cin >> n;
    vector<Point> a(2*n);
    for (int i=0; i<n; i++) {
        int start, end; cin >> start >> end;
        a[i*2] = {start, 1};
        a[i*2 +1] = {end, -1};
    }


    // 시작점 오름차순, 끝점이 우선 정렬
    sort(a.begin(), a.end());

    // 끝점 연산 우선으로 최대값 찾기
    int ans = 0;
    int cnt = 0;
    for (auto &x : a) {
        cnt += x.second;
        if (cnt > ans) ans = cnt;
    }

    // 출력
    cout << ans << '\n';
    return 0;
}