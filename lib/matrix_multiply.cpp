matrix operator * (matrix &a, matrix &b) {
    int n = a.size();
    int m = a[0].size();
    int r = b[0].size();
    matrix c(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<r; j++) {
            for (int k=0; k<m; k++) c[i][j] += a[i][k]*b[k][j];
        }
    }
    
    return c;
}