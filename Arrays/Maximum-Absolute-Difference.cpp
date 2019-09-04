int Solution::maxArr(vector<int> &A) {
    vector<int> diff, sum;
    int min_diff = INT_MAX, max_diff = INT_MIN;
    int min_sum = INT_MAX, max_sum = INT_MIN;
    for(int i = 0; i < A.size(); i++)
    {
        min_diff = min(A[i]-i, min_diff);
        max_diff = max(A[i]-i, max_diff);
        min_sum = min(A[i]+i, min_sum);
        max_sum = max(A[i]+i, max_sum);
    }
    return max(max_diff-min_diff, max_sum-min_sum);
}
