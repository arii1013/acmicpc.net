static int d[1001][1001];
for (int i=0; i<LIMIT; i++) {
    d[i][0] = d[i][i] = 1;
    for (int j=1; j<i; j++) d[i][j] = (d[i-1][j-1] + d[i-1][j]) % MOD;
}

vector<vector<int>> d(LIMIT, vector<int>(LIMIT, 1));
for (int i=2; i<LIMIT; i++) {
    for (int j=1; j<i; j++) d[i][j] = (d[i-1][j-1] + d[i-1][j]) % MOD;
}