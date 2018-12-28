/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareInterval(Interval a, Interval b)
{
    return (a.start < b.start);
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    stack<Interval> S;
    vector<Interval> B;
    sort(A.begin(), A.end(), compareInterval);
    S.push(A[0]);
    for(int i=1; i<A.size(); i++)
    {
        Interval T = S.top();
        if(T.end < A[i].start) S.push(A[i]);
        else if(T.end < A[i].end)
        {
            T.end = A[i].end;
            S.pop();
            S.push(T);
        }
    }
    while(!S.empty())
    {
        B.push_back(S.top());
        S.pop();
    }
    reverse(B.begin(), B.end());
    return B;
}
