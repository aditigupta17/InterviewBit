class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProd[n];
        int rightProd[n];
        int A[n];
        
        leftProd[0] = 1;
        for(int i=1; i<n; i++)
            leftProd[i] = leftProd[i-1] * nums[i-1];
        
        rightProd[n-1] = 1;
        for(int i=n-2; i>=0; i--)
            rightProd[i] = rightProd[i+1] * nums[i+1];
        
        for(int i=0; i<n; i++)
            A[i] = leftProd[i] * rightProd[i];
        
        vector<int> S;
        for(int i=0; i<n; i++)
            S.push_back(A[i]);
        
        return S;
    }
};
