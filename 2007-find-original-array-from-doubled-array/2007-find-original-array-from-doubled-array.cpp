class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int l = changed.size();
        if(l%2==1)return {};
        unordered_map<int,int> mp;
        for(int x:changed){
            mp[x]++;
        }
        
        sort(changed.begin(),changed.end());
        vector<int> res;
        for(int i=0;i<changed.size();i++){
                if(mp[changed[i]]==0)continue;
                if(mp[changed[i]*2]==0)return {};
                res.push_back(changed[i]);
                mp[changed[i]]--;
                mp[changed[i]*2]--;
        }
        return res;
    }
};
/*
1 2 3 4 6 8
*/