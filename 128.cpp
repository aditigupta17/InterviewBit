/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        if(A.empty()) return 0;
        sort(A.begin(), A.end());
        int len = 1, ans = 1;
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] == A[i-1]+1)
            {
                len++;
                ans = max(ans, len);
            }
            else if(A[i] != A[i-1]) len = 1;
        }
        return ans;
    }
};
