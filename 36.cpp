class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& A) {
        for(int i = 0; i < 9; i++)
        {
            unordered_set<int> rowCheck, colCheck;
            for(int j = 0; j < 9; j++)
            {
                if(isdigit(A[i][j]) && rowCheck.find(A[i][j]) != rowCheck.end()) return false;
                else rowCheck.insert(A[i][j]);
                if(isdigit(A[j][i]) && colCheck.find(A[j][i]) != colCheck.end()) return false;
                else colCheck.insert(A[j][i]);
            }
        }
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
            {
                int a = i, b = j;
                unordered_set<int> segCheck;
                for(int x = a; x < a + 3; x++)
                    for(int y = b; y < b + 3; y++)
                    {
                        if(isdigit(A[x][y]) && segCheck.find(A[x][y]) != segCheck.end()) return false;
                        else segCheck.insert(A[x][y]);
                    }
            }
        return true;
    }
};
