#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

// 점과 선에 대해 정의
using Point = pair<ll, ll>;
using Line = pair<Point, Point>;

// Counter ClockWise
int ccw(Point p1, Point p2, Point p3) {
    // 세 점에 대한 벡터의 외적 구하기
    ll tmp = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
    tmp -= (p1.second*p2.first + p2.second*p3.first + p3.second*p1.first);

    // 벡터의 외적 판단
    // 반시계 방향: 1; 일직선: 0; 시계 방향: -1
    if (tmp > 0) return 1;
    else if (tmp == 0) return 0;
    else return -1;
}

// 두 선분이 교차하는지 확인
int isIntersect(Line l1, Line l2) {
    // l1에 대한 l2, l2에 대한 l1의 ccw값 생성
    auto l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    auto l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);

    if (l1l2 == 0 && l2l1 == 0) {
        if (l1.first > l1.second) swap(l1.first, l1.second);
        if (l2.first > l2.second) swap(l2.first, l2.second);
        if (l1.first <= l2.first && l1.second <= l2.second) return 1;
    }

    // 두 선분이 교차하는 지 확인
    return ((l1l2 < 0 && l2l1 < 0) ? 1 : 0);
}

// 다각형의 내부에 존재하는 지 확인
int go(Point &p1, vector<Point> &p) {
    int n = p.size();
    
    // # 방벽 위에 존재하는 경우
    // 나와 방벽과의 위치 관계
    // ccw값이 0일 경우에 방벽 선분 위에 존재하는지 확인
    for (int i=0; i<n-1; i++) {
        auto t = ccw(p1, p[i], p[i+1]);
        if (t == 0) {
            auto minx = min(p[i].first, p[i+1].first);
            auto maxx = max(p[i].first, p[i+1].first);
            auto miny = min(p[i].second, p[i+1].second);
            auto maxy = max(p[i].second, p[i+1].second);
            
            if (minx <= p1.first && p1.first <= maxx) {
                if (miny <= p1.second && p1.second <= maxy) {
                    return 1;
                }
            }
        }
    }

    // # 방벽 내부에 존재하는 경우
    // 임의의 점 생성 후, 몇 개의 선분과 교차하는 지 확인
    // 교차 횟수가 짝수면 외부, 홀수면 내부
    Point p0 = {1, 2147483647};
    int cnt = 0;
    for (int i=0; i<n-1; i++) {
        Line l1 = {p0, p1};
        Line l2 = {p[i], p[i+1]};
        cnt += isIntersect(l1, l2);
    }
    return cnt%2;
}

int main() {
    FAST_IO

    // 입력값
    int n; cin >> n;
    vector<Point> p;
    while (n--) {
        Point tmp;
        cin >> tmp.first >> tmp.second;
        p.push_back(tmp);
    }
    p.push_back(p[0]);

    // 대연, 영훈, 범진의 정보를 받아 출력
    int m = 3;
    while (m--) {
        Point p1;
        cin >> p1.first >> p1.second;
        cout << go(p1, p) << '\n';
    }

    return 0;
}