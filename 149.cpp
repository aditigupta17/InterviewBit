class Solution {
public:
    int maxPoints(vector<vector<int>>& A) {
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            int dup = 1;
            map<pair<int, int>, int> M;
            for(int j = i + 1; j < A.size(); j++)
            {
                int x1 = A[i][0], x2 = A[j][0], y1 = A[i][1], y2 = A[j][1];
                if((x1 == x2) && (y1 == y2)) dup++;
                else if(x1 == x2) M[{INT_MAX, INT_MAX}]++;
                else
                {
                    int num = y2 - y1;
                    int den = x2 - x1;
                    int gcd = __gcd(num, den);
                    M[make_pair(num / gcd, den / gcd)]++;
                }
            }
            int temp = 0;
            for(auto it = M.begin(); it != M.end(); ++it)
                temp = max(temp, it->second);
            ans = max(ans, temp + dup);
        }
        return ans;
    }
};
