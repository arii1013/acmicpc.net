double polygon_area(vector<pair<ll, ll>> &points) {
    int n = points.size();
    points.push_back(points[0]);
    double ans = 0;

    for (int i=0; i<n; i++) {
        ans += points[i].first*points[i+1].second - points[i].second*points[i+1].first;
    }

    ans /= 2.0;
    if (ans < 0) ans *= -1;
    return ans;
}