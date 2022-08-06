class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,tmp=0;
        for(int i=1;i<prices.size();++i){
            tmp = max(0,tmp+prices[i]-prices[i-1]);
            profit = max(profit, tmp);
        }
        return profit;
    }
};

/**
[7,1,5,3,6,4]->0,4,2,5,3
[7,6,4,3,1]->0,0,0,0
[1,2,3,4,6]
**/