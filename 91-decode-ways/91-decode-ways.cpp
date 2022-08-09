class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(),ways = 0;
         vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = (s[0]=='0')?0:1;
        for(int i=2;i<=n;i++){
            int oneChar = stoi(s.substr(i-1,1));
            int twoChar = stoi(s.substr(i-2,2));
            if(oneChar>0)
                dp[i] = dp[i] + dp[i-1];
            if(twoChar>9 && twoChar<27)
                dp[i] = dp[i] + dp[i-2];    
        }
        return dp[n];
    }
};