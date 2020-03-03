bool isValid(vector<vector<char> > &A, int row, int col, char ch){
    for(int i = 0; i < 9; i++){
        if(A[i][col] != '.' && A[i][col] == ch) return false;
        if(A[row][i] != '.' && A[row][i] == ch) return false;
        int subGridRow = row/3, subGridCol = col/3;
        int x = (3 * subGridRow) + (i / 3), y = (3 * subGridCol) + (i % 3);
        if(A[x][y] != '.' && A[x][y] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char> > &A){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++){
            if(A[i][j] == '.'){
                for(int num = '1'; num <= '9'; num++){
                    if(isValid(A, i, j, num)){
                        A[i][j] = num;
                        if(solve(A)) return true;
                        else A[i][j] = '.';
                    }
                }
                return false;
            }
        }
    return true;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    if(A.size() == 0) return;
    solve(A);
}
