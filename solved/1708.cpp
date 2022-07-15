#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

// 점 정의와 convex_hull 기준점 선언
struct Point {
    ll x, y;
};
Point base;

// Counter ClockWise
int ccw(Point p1, Point p2, Point p3) {
    // 세 점에 대한 벡터의 외적 (신발끈 공식)
    ll tmp = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
    tmp -= p1.y*p2.x + p2.y*p3.x + p3.y*p1.x;

    // 벡터의 외적 판별
    // 반시계 방향: 1; 일직선: 0; 시계 방향: -1
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

// 두 점 사이의 거리 제곱
ll dist(Point p1, Point p2) {
    ll dx = p1.x - p2.x;
    ll dy = p1.y - p2.y;

    return dx*dx + dy*dy;
}

// 비교 함수
bool cmp(const Point &u, const Point &v) {
    int tmp = ccw(base, u, v);

    // convex_hull 기준점과 일직선 상에 있는 경우, 거리가 가까운 순으로 정렬
    if (tmp == 0) return dist(base, u) < dist(base, v);
    // convex_hull 기준점과 일직선 상에 없을 경우, ccw값이 반시계 방향 순으로 정렬
    else return tmp == 1;
}

int main() {
    FAST_IO

    // 입력
    int n; cin >> n;
    vector<Point> a(n);
    for (int i=0; i<n; i++) cin >> a[i].x >> a[i].y;

    // convex_hull 기준값 찾기
    // 최하단-최좌측에 위치한 점
    base = a[0];
    for (int i=1; i<n; i++) {
        if (a[i].y < base.y || (a[i].y == base.y && a[i].x < base.x)) {
            base = a[i];
        }
    }
    
    // convex_hull 기준점과 θ각이 가장 작은 순으로 정렬
    // θ각이 같다면 거리가 짧은 순으로 정렬
    sort(a.begin(), a.end(), cmp);

    // convex_hull 찾기
    vector<Point> convex_hull;
    for (int i=0; i<n; i++) {
        while (convex_hull.size() >= 2 && ccw(convex_hull[convex_hull.size()-2], convex_hull[convex_hull.size()-1], a[i]) <= 0) {
            convex_hull.pop_back();
        }
        convex_hull.push_back(a[i]);
    }

    // 출력
    cout << convex_hull.size() << '\n';
    return 0;
}