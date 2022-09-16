class Solution {
    int dp[1000][1000];
public:
    int helper(vector<int>& nums, vector<int>& multipliers,int l, int r, int k){
        int n = nums.size(), m = multipliers.size();
        
        if(k==m)return 0;//done exactly m operations
        
        if(dp[l][k]!=-1e9)return dp[l][k];
        
        int left = nums[l] * multipliers[k] + helper(nums,multipliers,l+1,r,k+1);
        int right = nums[r] * multipliers[k] + helper(nums,multipliers,l,r-1,k+1);
        
        dp[l][k] = max(left, right);
        
        return dp[l][k];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0;i<1000;i++)
            for(int j=0;j<1000;j++)
                dp[i][j] = -1e9;
        return helper(nums, multipliers, 0, nums.size()-1, 0);
    }
};

/***
Recursive approach O(2^n) time complexity
int helper(vector<int>& nums, vector<int>& multipliers,int l, int r, int k){
        int n = nums.size(), m = multipliers.size();
        if(k==m)return 0;//done exactly m operations
        int left = nums[l]*multipliers[k] + helper(nums,multipliers,l+1,r,k+1);
        int right = nums[r]*multipliers[k] + helper(nums,multipliers,l,r-1,k+1);
        return max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        return helper(nums, multipliers, 0, nums.size()-1, 0);
    }
***/