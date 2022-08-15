class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size(), c = r>0 ?matrix[0].size():0;
        vector<vector<int>> dp(r+1,vector<int>(c+1));
        int side = 0;
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1])) + 1;
                    side = max(side, dp[i][j]);
                }
            }
        }
        return side*side;
    }
};