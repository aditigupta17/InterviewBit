int Solution::maxSubArray(const vector<int> &A) {
    int curr = 0;
    int maxx = 0;
    for(int i = 0; i < A.size(); i++)
    {
        curr = curr + A[i];
        if(curr > maxx) maxx = curr;
    }
    return maxx;
}
