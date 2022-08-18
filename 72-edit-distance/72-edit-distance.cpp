class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        //Fill entire column for length 0 of string A, operation which can be performed to make it 
        // match to string B is insert  
        for(int j=1;j<=m;j++){
            dp[0][j] = j;
        }
        //Fill entire row for length 0 of string B, operation which can be performed to make it 
        // match to string A is delete characters from A
        for(int i=1;i<=n;i++){
            dp[i][0] = i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])
                    //if ith character matches than no operation required, move to next character
                    dp[i][j] = dp[i-1][j-1];
                else{
                    //if mismatch then either insert, replace or delete can be performed which takes 1 operation
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[n][m];
    }
};