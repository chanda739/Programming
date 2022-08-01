class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};

/*Error: expected 'ans' to have value from 1 to 2000000000 only
 int uniquePaths(int m, int n) {
        vector<vector<long>> dp(m, vector<long>(n,0));
        long mod = 2000000000;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j] = 1;
                else if(i==0||j==0)dp[i][j] = 1;
                else
                    dp[i][j] = ((dp[i-1][j])%mod + (dp[i][j-1])%mod)%mod;
            }
        }
        return (int)(dp[m-1][n-1]%mod);
    }
**/