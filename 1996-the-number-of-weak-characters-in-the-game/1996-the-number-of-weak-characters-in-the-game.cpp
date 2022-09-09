class Solution {
public:
    bool static comp(vector<int>& a,vector<int>&b){
        if(a[0]!=b[0])return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int l = properties.size();
        sort(properties.begin(),properties.end(),comp);
        int mx = INT_MIN,res=0;
        for(auto p:properties)
            if(mx>p[1])res++;
            else mx = p[1];
        return res;
    }
};