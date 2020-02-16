int Solution::maximumGap(const vector<int> &A) {
    int N = A.size();
    if(N < 2) return 0;
    int lo = *min_element(A.begin(), A.end());
    int hi = *max_element(A.begin(), A.end());
    int gap = max(1, (int)ceil((double)(hi - lo)/(N - 1)));
    int buckets = N - 1;
    vector<int> mn(buckets, INT_MAX);
    vector<int> mx(buckets, INT_MIN);
    for(int i = 0; i < N; i++){
        if(A[i] == lo || A[i] == hi) continue;
        int index = (A[i] - lo)/gap;
        mn[index] = min(mn[index], A[i]);
        mx[index] = max(mx[index], A[i]);
    }
    int prev = lo, maxGap = 0;
    for(int i = 0; i < N-1; i++){
        if(mn[i] == INT_MAX && mx[i] == INT_MIN) continue;
        maxGap = max(maxGap, mn[i] - prev);
        prev = mx[i];
    }
    return max(maxGap, hi - prev);
}
