/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.
*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size(), i;
    long long int x = (n*(n+1))/2;
    long long int y = (x*(2*n + 1))/3;
    for(i = 0; i < n; i++)
    {
        x -= (long long)A[i];
        y -= (long long)A[i]*A[i];
    }
    vector<int> ans;
    ans.push_back(int(((y/x)+x)/2));
    ans.push_back(int(((y/x)-x)/2));
    return ans;
}
