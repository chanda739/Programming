class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int l = nums.size();
        int mSum = nums[0], sum = nums[0];
        for(int i=1;i<l;i++){
            sum = max(sum, 0) + nums[i];
            mSum = max(mSum, sum);
        }
        
        vector<int> rSum(l,0);
        rSum[l-1] = nums[l-1];
        for(int i=l-2;i>=0;i--){
            rSum[i] = rSum[i+1] + nums[i];
        }
        
        vector<int> rmSum(l,0);
        rmSum[l-1] = nums[l-1];
        for(int i=l-2;i>=0;i--){
            rmSum[i] = max(rmSum[i+1], rSum[i]);
        }
        
        int lSum = 0;
        for(int i=0;i<l-2;i++){
            lSum += nums[i];
            mSum = max(mSum, lSum + rmSum[i+2]);
        }
        return mSum;
    }
};