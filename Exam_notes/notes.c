void computeS(int m, int n) {
    if (M[m][n] != 0) {
        S[m][n] = max(S[m-1][n-1], S[m-1][n], S[m][n-1]);
    } else {
        S[m][n] = 1 + max(S[m-1][n-1], S[m-1][n], S[m][n-1]);
    }
}