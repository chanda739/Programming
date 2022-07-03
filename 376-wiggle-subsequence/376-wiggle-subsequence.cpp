class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ps = 1, ng = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])ps = ng+1;
            else if(nums[i]<nums[i-1])ng = ps+1;
        }
        return max(ps,ng);
    }
};