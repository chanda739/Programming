class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for(int i=0;i<n;i++)dp[i][i] = 1;
        
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j = i+l-1;
                if(s[i]==s[j] && l==2)dp[i][j] = 2;
                else if(s[i]==s[j])dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
/***MLE
    int lcs(string s, int i, string r, int j,vector<vector<int>> &dp){
        if(i==-1||j==-1)return 0;
        if(dp[i][j]==-1){
            if(s[i]==r[j])dp[i][j] = 1 + lcs(s,i-1,r,j-1,dp);
            else dp[i][j] = max(lcs(s,i-1,r,j,dp), lcs(s,i,r,j-1,dp));
        }
        return dp[i][j];
    }
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<=1)return s.size();
        string revs = s;
        reverse(revs.begin(),revs.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        lcs(s,s.size()-1,revs,s.size()-1,dp);
        return dp[s.size()-1][s.size()-1];
    }
    ***/