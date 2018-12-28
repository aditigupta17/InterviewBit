vector<int> Solution::getRow(int A) {
    vector<int> S;
    S.push_back(1);
    for(int i=1; i<=A; i++)
        S.push_back((S[i-1]*(A-i+1))/i);
    return S;
}
