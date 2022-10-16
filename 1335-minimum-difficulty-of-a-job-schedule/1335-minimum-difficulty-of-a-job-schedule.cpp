class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int l = jobDifficulty.size(),mx = 1e9, t;
        if(l<d)return -1;
        vector<int> dp(l+1, 1e9);
        dp[l]= 0;
        for(int k=1;k<=d;++k){
            for(int i=0;i<=l-k;++i){
                t = 0, dp[i] = mx;
                for(int j=i;j<=l-k;++j){
                    t = max(t, jobDifficulty[j]);
                    dp[i]  = min(dp[i], t + dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};