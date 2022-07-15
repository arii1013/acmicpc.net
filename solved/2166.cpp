#include <iostream>
#include <vector>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using Point = pair<ll, ll>;

void getAreaofPolygon(vector<Point> &p) {
    int n = p.size();

    // n개의 점에 대한 |벡터의 외적| 값 구하기
    ll area = 0;
    for (int i=0; i<n-1; i++) {
        area += p[i].first*p[i+1].second;
        area -= p[i].second*p[i+1].first;
    }
    if (area < 0) area = -area;

    // 다각형의 넓이의 정수부와 소수부 출력
    // 정수를 2로 나눌 경우 홀수면 실수부는 5, 짝수면 0이다.
    cout << area/2 << '.' << (area%2 == 1 ? 5 : 0) << '\n';

    return;
}

int main() {
    FAST_IO

    // 입력값
    int n; cin >> n;
    vector<Point> p;
    while(n--) {
        Point tmp;
        cin >> tmp.first >> tmp.second;
        p.push_back(tmp);
    }
    p.push_back(p[0]);

    // 정답 출력
    getAreaofPolygon(p);

    return 0;
}