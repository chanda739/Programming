class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        int res = 0;
        dp[0] = 0;
        //cout<<dp[0]<<" ";
        for(int i=1;i<=n;i++){
            res = i;
           // cout<<res<<" res ";
            for(int j=1;j*j<=i;j++){
                res = min(res,dp[i-j*j]+1);
            }

            dp[i] = res;
            //cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};