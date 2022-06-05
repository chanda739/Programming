class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdegree(n+1,0);
        vector<int> indegree(n+1,0);
        int m = trust.size();
        vector<int> graph[n+1];
        
            for(int j=0;j<m;j++){
                graph[trust[j][0]].push_back(trust[j][1]);
                indegree[trust[j][1]]++;
                outdegree[trust[j][0]]++;
            }
        for(int i=1;i<=n;i++){
            if(indegree[i]==n-1 && outdegree[i]==0){
                return i;
            }
        }
        return -1;
    }
};