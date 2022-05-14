class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int l  = times.size(),u,v,w;
        vector<int> traveltime(n+1,INT_MAX);
        traveltime[k] = 0;
        for(int i = 0; i < n;i++){
            for(vector<int> edge : times){
                u = edge[0], v = edge[1], w = edge[2];
                if(traveltime[u]!=INT_MAX && traveltime[v] > traveltime[u] + w){
                    traveltime[v] = traveltime[u] + w;
                }
            }
        }
        
        int maxtime = 0;
        for(int i = 1; i <= n; i++){
            maxtime = max(maxtime, traveltime[i]);
        }
        return maxtime==INT_MAX? -1 : maxtime;
    }
};