class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //[7,1,5,3,6,4]->-6,4,-2,3,-2 add all positive profits
        //buy and sell on alternate days and add up all profits
        int l = prices.size(),profit = 0;
        for(int i=1;i<l;i++)
            profit += (prices[i-1]<prices[i])?(prices[i] - prices[i-1]):0;
        return profit;
    }
};