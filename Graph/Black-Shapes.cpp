int X[4] = {0, 0, -1, 1};
int Y[4] = {1, -1, 0, 0};
void dfs(vector<string> &A, int i, int j){
    A[i][j] = 'O';
    for(int k = 0; k < 4; k++){
        int x = i + X[k];
        int y = j + Y[k];
        if(x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && A[x][y] == 'X') 
            dfs(A, x, y);
    }
}
 
int Solution::black(vector<string> &A) {
    int ans = 0, R = A.size(), C = A[0].size();
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++){
            if(A[i][j] == 'X'){
                ++ans;
                dfs(A, i, j);
            }
        }
    return ans;
 }
