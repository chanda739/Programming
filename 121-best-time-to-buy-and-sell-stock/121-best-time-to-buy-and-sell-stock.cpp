class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, t = 0;
        for(int i=1;i<prices.size();i++){
            t = max(0, t + prices[i]-prices[i-1]);
                res = max(t, res);
        }
        return res;
    }
};
