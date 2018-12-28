int Solution::uniquePaths(int A, int B) {
    int S[A][B];
    for(int i=0; i<B; i++) S[0][i] = 1;
    for(int i=0; i<A; i++) S[i][0] = 1;
    for(int i=0; i<A; i++)
        for(int j=0; j<B; j++)
            S[i][j] = S[i-1][j] + S[i][j-1];
    return S[A-1][B-1];
}
