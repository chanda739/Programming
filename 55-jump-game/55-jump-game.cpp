class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        int i=0,jumps = nums[0];
        for(i=1;i<l;i++){
            jumps--;
            if(jumps<0)return false;
            if(nums[i]>jumps)jumps = nums[i];
        }
        return true;
    }
};
