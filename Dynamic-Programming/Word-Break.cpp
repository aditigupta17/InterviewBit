int Solution::wordBreak(string A, vector<string> &B) {
    int N = A.size();
    unordered_set<string> S(B.begin(), B.end());
    vector<bool> dp(N + 1, false);
    dp[0] = true;
    for(int i = 1; i <= N; i++)
        for(int j = i-1; j >= 0; j--)
            if(dp[j] && S.count(A.substr(j, i - j))){
                dp[i] = true;
                break;
            }
    return dp[N];
}
