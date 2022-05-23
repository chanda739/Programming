class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> dp(n, vector<int> (m,0));
        //If start itself is blocked so no way to go
        if(A[0][0]==1)
            return 0;

        dp[0][0] = 1;
        //1st row
        for(int i = 1;i<m;i++){
            if(A[0][i]==1)
                break;
            else
                dp[0][i] = 1;
        }
        //1st col
        for(int i = 1;i<n;i++){
            if(A[i][0]==1)
                break;
            else
                dp[i][0] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(A[i][j]==1)
                    continue;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};