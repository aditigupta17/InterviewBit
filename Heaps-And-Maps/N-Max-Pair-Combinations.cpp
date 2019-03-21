vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> T;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int N = A.size();
    // Max heap which stores tuple of the form <sum, (i, j)>
    priority_queue<pair<int, pair<int, int> > > P;
    set<pair<int, int> > S;
    P.push(make_pair(A[N-1] + B[N-1], make_pair(N-1, N-1)));
    S.insert(make_pair(N-1, N-1));
    for(int i=0; i<N; i++)
    {
        pair<int, pair<int, int>> temp = P.top();
        P.pop();
        T.push_back(temp.first);
        int a = temp.second.first;
        int b = temp.second.second;
        int sum = A[a-1] + B[b];
        pair<int, int> indexPair = make_pair(a-1, b);
        if(S.find(indexPair) == S.end())
        {
            P.push(make_pair(sum, indexPair));
            S.insert(indexPair);
        }
        
        sum = A[a] + B[b-1];
        indexPair = make_pair(a, b-1);
        if(S.find(indexPair) == S.end())
        {
            P.push(make_pair(sum, indexPair));
            S.insert(indexPair);
        }
    }
    return T;
}
