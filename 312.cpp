class Solution {
public:
    int maxCoins(vector<int>& A) {
        if(A.empty()) return 0;
        int n = A.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        // iterate through subarrays of all possible lengths
        for(int len = 1; len <= n; len++)
        {
            // starting index
            for(int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1; // ending index
                // iterating through taking each element to be the last balloon burst
                for(int k = i; k <= j; k++)
                {
                    int left = ((i == 0) ? 1 : A[i-1]);
                    int right = ((j == n-1) ? 1 : A[j+1]);
                    int before = ((i == k) ? 0 : dp[i][k-1]);
                    int after = ((j == k) ? 0 : dp[k+1][j]);
                    dp[i][j] = max(dp[i][j], before + (left * A[k] * right) + after);
                }
            }
        }
        return dp[0][n-1];
    }
};
