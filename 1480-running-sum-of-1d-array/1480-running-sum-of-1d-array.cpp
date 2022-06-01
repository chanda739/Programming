class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int l = nums.size();
        vector<int> sum(l,0);
        sum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            sum[i] = nums[i] + sum[i-1];
        }
        return sum;
    }
};