vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > S;
    for(int i=0; i<A; i++)
    {
        vector<int> B;
        B.push_back(1);
        for(int j=1; j<=i; j++)
            B.push_back((B[j-1]*(i-j+1))/j);
        S.push_back(B);
    }
    return S;
}
