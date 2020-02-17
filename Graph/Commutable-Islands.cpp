// Using Prim MST Algorithm
int MST(int N, vector<vector<int> > &A){
    int minCost = 0;
    vector<pair<int, int>> G[N+1];
    for(int i = 0; i < A.size(); i++){
        G[A[i][0]].push_back(make_pair(A[i][2], A[i][1]));
        G[A[i][1]].push_back(make_pair(A[i][2], A[i][0]));
    }
    vector<bool> vis(N+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 1));
    while(!Q.empty()){
        pair<int, int> v = Q.top();
        Q.pop();
        if(vis[v.second]) continue;
        minCost += v.first;
        vis[v.second] = true;
        for(int i = 0; i < G[v.second].size(); i++){
            if(!vis[G[v.second][i].second]) Q.push(G[v.second][i]);
        }
    }
    return minCost;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int minCost = MST(A, B);
    return minCost;
}
