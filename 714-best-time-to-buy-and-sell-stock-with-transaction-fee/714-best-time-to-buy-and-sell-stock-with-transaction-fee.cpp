class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i=1;i<prices.size();++i){
            cash = max(cash, hold+prices[i]-fee);//sell
            hold = max(hold, cash-prices[i]);//buy
        }
        return cash;
    }
};