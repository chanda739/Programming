class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)return 1;
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = 0, dp[2] = 1;
        for(int i=0;i<=n;++i){
            for(int j=0;j<i;++j){
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
            }
        }
        return dp[n];
    }
};