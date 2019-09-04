class Solution {
public:
    void moveZeroes(vector<int>& A) {
        int count = 0;
        for(int i = 0; i < A.size(); i++)
            if(A[i] == 0) count++;
        int end = A.size() - count;
        int start = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(A[i] != 0)
            {
                A[start] = A[i];
                start++;
            }
        }
        for(int i = end; i < A.size(); i++)
            A[i] = 0;
    }
};
