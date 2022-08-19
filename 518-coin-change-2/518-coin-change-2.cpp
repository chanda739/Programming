class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int l = coins.size();
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int j=0;j<l;j++){
            for(int i=1;i<=amount;i++){
                if(coins[j]<=i){
                    dp[i] += dp[i-coins[j]];
                }
            }
        }
        return dp[amount];
    }
};