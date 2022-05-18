class Solution {
public:
    int dfs(vector<int> graph[], int n, int vertex, int currRank, vector<int> &ranks, vector<vector<int>> &res){
        if(ranks[vertex]!=-2){
            return ranks[vertex];
        }
        
        int low = currRank;
        ranks[vertex] = currRank;
        
        for(auto neighbour:graph[vertex]){
            if(ranks[neighbour]==currRank-1 || ranks[neighbour]==n)
                continue;
            
            int neighbourRank = dfs(graph, n, neighbour, currRank+1, ranks, res);
            low = min( low, neighbourRank);
            if(neighbourRank > currRank)
                res.push_back({min(vertex,neighbour), max(vertex,neighbour)});
        }
        ranks[vertex] = n;
        return low;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for(auto x : connections){
            graph[x[0]].push_back(x[1]);
             graph[x[1]].push_back(x[0]);
        }
        vector<int> ranks(n,-2);
        vector<vector<int>> res;
        dfs(graph, n, 0, 0, ranks, res);
        return res;
    }
};