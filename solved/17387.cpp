#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using Point = pair<ll, ll>;
using Line = pair<Point, Point>;

// Counter Clockwise
int ccw(Point p1, Point p2, Point p3) {
    // 벡터의 외적 구하기 (신발끈 공식)
    ll temp = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
    temp -= (p1.second*p2.first + p2.second*p3.first + p3.second*p1.first);

    // 벡터의 외적 판별
    // 반시계 방향: 1; 일직선: 0; 시계 방향: -1
    if (temp > 0) return 1;
    else if (temp == 0) return 0;
    else return -1;
}

// 두 선분이 교차하는지 검증
bool isIntersect(Line &l1, Line &l2) {
    auto l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    auto l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);

    // 선분의 ccw값이 0인 경우는 세 점이 한 선분 위에 존재할 때
    // 두 선분이 한 선분 위에 존재할 때
    if (l1l2 == 0 && l2l1 == 0) {
        if (l1.first > l1.second) swap(l1.first, l1.second);
        if (l2.first > l2.second) swap(l2.first, l2.second);
        return l2.first <= l1.second && l1.first <= l2.second;
    }

    // 두 선분이 교차하거나 접해있을 경우
    return (l1l2 <= 0 && l2l1 <= 0);
}

int main() {
    FAST_IO

    // 입력값
    Point p1, p2, p3, p4;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    cin >> p3.first >> p3.second >> p4.first >> p4.second;
    Line l1 = {p1, p2}, l2 = {p3, p4};

    // 출력
    cout << (isIntersect(l1, l2) ? 1 : 0) << '\n';

    return 0;
}