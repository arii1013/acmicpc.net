#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[1000][1000];

// 가장 넓은 직사각형 넓이 구하기
int go(vector<int> &b) {
    int n = b.size();
    stack<int> s;
    int ans = 0;

    // 세로로 가장 넓은 직사각형 찾기
    for (int i=0; i<n; i++) {
        // 히스토그램의 높이가 전보다 작아진다면 전 막대와 같은 높이의 직사각형 넓이 구하기
        // 히스토그램의 높이가 전보다 작아진다는 의미는 그 전 부분이 솟아있다는 의미이다.
        while (!s.empty() && b[s.top()] > b[i]) {
            int height = b[s.top()];
            s.pop();
            int width = i;
            if (!s.empty()) width = i-1 - s.top();
            if (width*height > ans) ans = width*height;
        }

        s.push(i);
    }

    // 가로로 가장 넓은 직사각형 찾기
    while (!s.empty()) {
        int height = b[s.top()];
        s.pop();
        int width = n;
        if (!s.empty()) width = n-1 - s.top();
        if (width*height > ans) ans = width*height;
    }
    
    // 가장 넓은 직사각형 넓이 리턴
    return ans;
}

int main() {
    FAST_IO

    int n, m;
    while (true) {
        // 입력 및 종료 조건
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> a[i][j];
            }
        }

        // 0~n행 히스토그램 생성 후, 히스토그램에 대한 최대 직사각형의 넓이 구하기
        vector<int> b(m);
        int ans = 0;
        for (int i=0; i<n; i++) {
            // 0~i행 히스토그램 생성
            for (int j=0; j<m; j++) {
                if (a[i][j] == 0) b[j] = 0;
                else b[j] += 1;
            }

            // 히스토그램에서 직사각형의 최대 넓이 구하기
            auto tmp = go(b);
            if (tmp > ans) ans = tmp;
        }

        // 각 케이스에 대한 정답 출력
        cout << ans << '\n';
    }

    return 0;
}