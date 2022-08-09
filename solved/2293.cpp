#include <iostream>
#include <algorithm>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int a[100];
int d[10000+1];

int main() {
    FAST_IO

    // 입력받고 동전의 가치를 오름차순으로 정렬
    int n, k; cin >> n >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    // dp: 
    // d[j+a[i]] = d[j+a[i]] + d[j]
    d[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j+a[i]<=k; j++) {
            d[j+a[i]] = d[j+a[i]] + d[j];
        }
    }
    
    // 출력
    cout << d[k] << '\n';
    return 0;
}