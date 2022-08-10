class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1] = 1;
        for(int i=2;i<=n;++i)
            for(int j=1;j<=i;++j)
                dp[i] = dp[i] + dp[j-1]*dp[i-j];
        return dp[n];
    }
};

/*
We can use Catalan Number to get number of unique BST or BT which can be formed using no. 1 to n
nCn = (2n)!/(n+1)!*n! -> BST
nCn = (2n)!/(n+1)! ->BT
*/