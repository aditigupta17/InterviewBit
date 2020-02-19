// O(N^2) DP
int Solution::lis(const vector<int> &A) {
    if(A.size() == 0) return 0;
    int N = A.size(), ans = 1;
    vector<int> S(N, 1);
    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++){
            if(A[j] < A[i]) S[i] = max(S[i], S[j] + 1);
            ans = max(ans, S[i]);
        }
    return ans;
}
