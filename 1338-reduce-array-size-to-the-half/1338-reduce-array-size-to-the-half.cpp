class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int x:arr)mp[x]++;
        
        priority_queue<pair<int,int>> pq;
        for(auto x=mp.begin();x!=mp.end();x++){
            pq.push({x->second,x->first});
        }
        int res = 0,t = n;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            t = t-p.first;
            res++;
            if(t<=(n/2)){
                return res;
            }
            pq.pop();
        }
        return res;
    }
};