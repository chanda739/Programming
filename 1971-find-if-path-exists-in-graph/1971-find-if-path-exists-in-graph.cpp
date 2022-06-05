class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        
        vector<int> graph[n];
        
        for(int i=0;i<m;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> visited(n,0);
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            visited[u] = 1;
            if(visited[destination]==1)
                return true;
            for(auto v : graph[u]){
                if(visited[v]==0){
                    q.push(v); 
                }
            }
        }
        return false;
    }
};