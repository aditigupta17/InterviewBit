bool isValid(int i, int j, int N, int M){
    if(i >= 0 && i < N && j >= 0 && j < M) return true;
    return false;
}
int X[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int i, int j, vector<vector<int> > &A){
    int N = A.size(), M = A[0].size(); 
    for(int k = 0; k < 8; k++){
        int x = i + X[k], y = j + Y[k];
        if(isValid(x, y, N, M) && A[x][y] == 1){
            A[x][y] = 0;
            DFS(x, y, A);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int count = 0;
    int N = A.size(), M = A[0].size();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(A[i][j] == 1){
                DFS(i, j, A);
                ++count;
            }
    return count;
}
