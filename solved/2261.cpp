#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

// 점 구조체 정의 및 lower/upper bound 처리를 위한 비교 함수 정의
struct Point {
    int x, y;
    bool operator < (const Point &v) const {
        if (y == v.y) return x < v.x;
        else return y < v.y;
    }
};

// 정렬 함수: 구조체 Point의 x값이 작은 순서로 정렬
bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}

// 거리 차의 제곱을 구하는 함수
int dist(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) cin >> a[i].x >> a[i].y;

    // x값이 작은 순으로 정렬
    sort(a.begin(), a.end(), cmp);

    // 라인 스위핑
    int ans = dist(a[0], a[1]);
    set<Point> candidate = {a[0], a[1]};
    int start = 0;
    for (int i=2; i<n; i++) {
        // 현재까지 구한 두 점 사이의 최소거리(ans)로 x축만 비교해서 후보자 관리
        Point now = a[i];
        while (start < i) {
            auto p = a[start];
            int x = p.x - a[i].x;
            if (x*x > ans) {
                candidate.erase(p);
                start++;
            } else {
                break;
            }
        }

        // 현재까지 구한 두 점 사이의 최소거리(ans->d)로 y축만 비교해서 후보자 중에서 ans값 갱신
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = Point({-100000, now.y-d});
        auto upper_point = Point({100000, now.y+d});
        auto lower_bound = candidate.lower_bound(lower_point);
        auto upper_bound = candidate.upper_bound(upper_point);
        for (auto it = lower_bound; it != upper_bound; it++) {
            int d = dist(now, *it);
            if (d < ans) ans = d;
        }

        candidate.insert(now);
    }

    // 출력
    cout << ans << '\n';
    return 0;
}