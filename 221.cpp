class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns
        int A[m+1][n+1];
        for(int i=0; i<=m; i++)
            A[i][0] = 0;
        for(int i=0; i<=n; i++)
            A[0][i] = 0;
        int maxx = 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(matrix[i-1][j-1] == '1')
                    A[i][j] = min(A[i][j-1], min(A[i-1][j-1], A[i-1][j])) + 1;
                else A[i][j] = 0;
                maxx = max(A[i][j], maxx);
            }
        }
        return (maxx * maxx);
    }
};
