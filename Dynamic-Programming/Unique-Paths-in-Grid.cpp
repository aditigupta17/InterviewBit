int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    if(A[0][0] == 1) return 0;
    int r = A.size(), c = A[0].size();
    A[0][0] = 1;
    for(int i = 1; i < c; i++){
        if(A[0][i] == 1) A[0][i] = 0;
        else A[0][i] = A[0][i-1];
    }
    for(int i = 1; i < r; i++){
        if(A[i][0] == 1) A[i][0] = 0;
        else A[i][0] = A[i-1][0];
    }
    for(int i = 1; i < r; i++)
        for(int j = 1; j < c; j++){
            if(A[i][j] == 1) A[i][j] = 0;
            else A[i][j] = A[i-1][j] + A[i][j-1];
        }
    return A[r-1][c-1];
}
