class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &dp, int i, int j, int m, int n){
        if(dp[i][j]==0){
            int temp = matrix[i][j];
            dp[i][j] = 1 + max(
            (i>0 and temp > matrix[i-1][j])?dfs(matrix, dp, i-1, j, m, n):0,
            max((j>0 and temp > matrix[i][j-1])?dfs(matrix, dp, i, j-1, m, n):0,
            max((i<m-1 and temp > matrix[i+1][j])?dfs(matrix, dp, i+1, j, m, n):0,
            (j<n-1 and temp > matrix[i][j+1])?dfs(matrix, dp, i, j+1, m, n):0))
            );
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int res = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res, dfs(matrix, dp, i, j, m, n));
               // dp[i][j] = 1 + max(dp[i-1][j], min(dp[i][j-1], min(dp[i+1][j], dp[i][j+1])));
                
            }
        }
        return res;
    }
};
