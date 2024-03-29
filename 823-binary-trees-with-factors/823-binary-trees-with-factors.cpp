class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9+7;
        vector<long> dp(n,1);
        map<int, int> mp;
        sort(arr.begin(), arr.end());
        for(int i=0;i<n;i++)mp[arr[i]] = i;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(arr[i]%arr[j]==0){
                    int fact = arr[i]/arr[j];
                    if(mp.find(fact)!=mp.end()){
                        dp[i] = (dp[i] + dp[j]*dp[mp[fact]])%mod;
                    }
                }
            }
        }
        long res = 0;
        for(int i=0;i<n;i++)res+=dp[i];
        return (int)(res%mod);
    }
};