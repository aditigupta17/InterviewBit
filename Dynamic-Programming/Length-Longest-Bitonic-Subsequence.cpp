int Solution::longestSubsequenceLength(const vector<int> &A) {
    vector<int> S, T;
    // for bitonic sequence, find longest increasing from left and right
    // add them, find max, subtract 1
    for(int i=0; i<A.size(); i++)
    {
        S.push_back(1);
        T.push_back(1);
    }
    for(int i=1; i<S.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j]<A[i])
            S[i] = max(S[i], S[j]+1);
        }
    }
    for(int i=T.size()-2; i>=0; i--)
    {
        for(int j=T.size()-1; j>i; j--)
        {
            if(A[j]<A[i])
            T[i] = max(T[i], T[j]+1);
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<A.size(); i++)
        ans = max(ans, S[i]+T[i]);
    return ans-1;
}
