#include <iostream>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

// Counter ClockWise
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    // 벡터의 외적 (신발끈 공식)
    int temp = x1*y2 + x2*y3 + x3*y1;
    temp -= y1*x2 + y2*x3 + y3*x1;

    // 세 점의 형태에 따른 리턴값
    // 반시계 방향: 1; 일직선: 0; 시계 방향: -1;
    if (temp > 0) return 1;
    else if (temp == 0) return 0;
    else return -1;
}

int main() {
    FAST_IO

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << ccw(x1, y1, x2, y2, x3, y3) << '\n';

    return 0;
}