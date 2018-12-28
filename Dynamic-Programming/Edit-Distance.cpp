int Solution::minDistance(string A, string B) {
    int m = A.length();
    int n = B.length();
    int S[m+1][n+1];
    for(int i=0; i<=n; i++) S[0][i] = i;
    for(int i=0; i<=m; i++) S[i][0] = i;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(A[i-1] == B[j-1]) S[i][j] = S[i-1][j-1];
            else S[i][j] = min(S[i-1][j-1], min(S[i-1][j], S[i][j-1]))+1;
        }
    return S[m][n];
}
