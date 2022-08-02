class Solution {
    int helper(vector<int>& nums){
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int> dp(n,0);
        dp[0] = nums[0], dp[1] = max(dp[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0], nums[1]);
        vector<int> x1(nums.begin(),nums.end()-1);
        vector<int> x2(nums.begin()+1,nums.end());
        return max(helper(x1), helper(x2));
    }
};
//Rob either house from 0 to n-2 or 1 to n-1, as we can't rob 1st and last house