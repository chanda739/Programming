class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> st;
        
        for(int i=0;i<arr.size();++i)
            mp[arr[i]]++;
        
        for(auto m:mp)
            st.insert(m.second);
        return st.size()==mp.size();
    }
};