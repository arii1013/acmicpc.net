#define ll long long
using Point = pair<ll, ll>;
using Line = pair<Point, Point>;

int ccw(Point p1, Point p2, Point p3) {
    ll temp = p1.first*p2.second + p2.first*p3.second + p3.first*p1.second;
    temp -= p1.second*p2.first + p2.second*p3.first + p3.second*p1.first;

    if (temp < 0) return 1;
    else if (temp > 0) return -1;
    else return 0;
}

bool check(Line l1, Line l2) {
    int l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    int l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);

    if (l1l2 == 0 && l2l1 == 0) {
        if (l1.first > l1.second) swap(l1.first, l1.second);
        if (l2.first > l2.second) swap(l2.first, l2.second);
        return l1.first <= l2.second && l2.first <= l1.second;
    } 
    return l1l2 <= 0 && l2l1 <= 0;
}