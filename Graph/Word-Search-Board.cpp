/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The cell itself does not count as an adjacent cell.
The same letter cell may be used more than once.
*/

bool DFS( vector<string> &A, int i, int j, string& B)
{
    if(B.size() == 0) return true;
    if( i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] != B[0])
        return false;
    string s = B.substr(1);
    bool ans = DFS(A, i+1, j, s) || DFS(A, i-1, j, s) || DFS(A, i, j+1, s) || DFS(A, i, j-1, s);
    return ans;
}

int Solution::exist(vector<string> &A, string B) {
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < A[0].size(); j++)
            if(DFS(A, i, j, B)) return 1;
    return 0;
}


