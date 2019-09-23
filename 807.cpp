class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& A) {
        // find max of each row and col
        vector<int> maxRow, maxCol;
        for(int i = 0; i < A.size(); i++)
        {
            int mx = INT_MIN;
            for(int j = 0; j < A[i].size(); j++)
                mx = max(mx, A[i][j]);
            maxRow.push_back(mx);
        }
        for(int i = 0; i < A[0].size(); i++)
        {
            int mx = INT_MIN;
            for(int j = 0; j < A.size(); j++)
                mx = max(mx, A[j][i]);
            maxCol.push_back(mx);
        }
        // element = min(maxRow, maxCol); sum it up
        int sum = 0;
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < A[i].size(); j++)
                sum += (min(maxRow[i], maxCol[j]) - A[i][j]);
        return sum;
    }
};
