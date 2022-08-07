class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size();
        vector<int> buy(n,0), sell(n,0);
        buy[0] = -prices[0];
        
        for(int i=1;i<n;i++){
            //sell on ith day by not selling on i-1 th day or by buying on i-1th day 
            sell[i] = max(sell[i-1] - prices[i-1], buy[i-1]) + prices[i];
            if(res<sell[i])
                res = sell[i];
            
            if(i==1)
                buy[i] = -prices[i];
            else
                buy[i] = max(buy[i-1] + prices[i-1], sell[i-2]) - prices[i];
            //buy on ith day by not buying on i-1 th day or selling on i-2th day and rest on i-1th day
        }
        return res;
    }
};

/**
buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);   
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
**/
