class Solution {
public:
    bool checkCycle(vector<vector<int>> &G, int i, bool *visited, bool *path)
    {
        visited[i] = 1;
        path[i] = 1;
        for(auto j : G[i])
        {
            if(path[j]) return true;
            if(!visited[j] && checkCycle(G, j, visited, path)) return true;
        }
        path[i] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        for(auto i : prerequisites)
            G[i.second].push_back(i.first);
        bool visited[numCourses] = {0};
        bool path[numCourses] = {0};
        
        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i] && checkCycle(G, i, visited, path))
                return false;
        }
        return true;
    }
};
