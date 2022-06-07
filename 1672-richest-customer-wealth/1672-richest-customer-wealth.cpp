class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richestCustomerBalance =INT_MIN,i,j,sum=0;
        for(i=0;i<accounts.size();i++){
            sum=0;
            for(j=0;j<accounts[i].size();j++){
                sum+=accounts[i][j];
            }
            if(richestCustomerBalance<sum)
                richestCustomerBalance = sum;
        }
        return richestCustomerBalance;
    }
};