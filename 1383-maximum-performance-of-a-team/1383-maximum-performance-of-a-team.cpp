class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> spef;
        for(int i=0;i<n;i++){
            spef.push_back({efficiency[i],speed[i]});
        }
        sort(rbegin(spef),rend(spef));
        priority_queue<int, vector<int>, greater<int>> pq;
        long sum = 0, mprf = 0;
        for(auto& [e,s]:spef){
            pq.emplace(s);
            sum+=s;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            mprf = max(mprf, sum*e);
        }
        return mprf%(int)(1e9+7);
    }
};
/*
9,1
7,5
5,2
4,10
3,3
2,8
*/