int Solution::solve(int N, vector<int> &B, vector<int> &C) {
    vector<int> G[N+1], indegree(N+1, 0);
    for(int i = 0; i < B.size(); i++){
        G[B[i]].push_back(C[i]);
        ++indegree[C[i]];
    }
    queue<int> Q;
    for(int i = 1; i <= N; i++)
        if(indegree[i] == 0) Q.push(i);
    while(!Q.empty()){
        int curr = Q.front(); Q.pop(); --N;
        for(auto next : G[curr])
            if(--indegree[next] == 0) Q.push(next);
    }
    return N == 0;
}
