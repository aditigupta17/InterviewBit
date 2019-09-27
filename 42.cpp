class Solution {
public:
    int trap(vector<int>& A) {
        if(A.empty()) return 0;
        int n = A.size();
        vector<int> maxLeft(n), maxRight(n);
        maxLeft[0] = -1, maxRight[n-1] = -1;
        int maxSoFar = A[0];
        for(int i = 1; i < n; i++)
        {
            if(maxSoFar > A[i]) maxLeft[i] = maxSoFar;
            else maxLeft[i] = -1;
            maxSoFar = max(maxSoFar, A[i]);
        }
        maxSoFar = A[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            if(maxSoFar > A[i]) maxRight[i] = maxSoFar;
            else maxRight[i] = -1;
            maxSoFar = max(maxSoFar, A[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(maxLeft[i] != -1 && maxRight[i] != -1)
                sum += (min(maxLeft[i], maxRight[i]) - A[i]);   
        }
        return sum;
    }
};
