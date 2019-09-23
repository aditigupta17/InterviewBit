class Solution {
public:
    int findJudge(int N, vector<vector<int>>& A) {
        vector<bool> isJudge(N, true);
        vector<int> isTrusted(N, 0);
        for(int i = 0; i < A.size(); i++)
        {
            int p1 = A[i][0] - 1;
            int p2 = A[i][1] - 1;
            isJudge[p1] = false;
            isTrusted[p2]++;
        }
        for(int i = 0; i < N; i++)
        {
            if(isTrusted[i] == N-1 && isJudge[i])
                return (i+1);
        }
        return -1;
    }
};
