class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i, res = 0, n = nums.size();
        for(i=0;i<nums.size();i++){
            res = res^i^nums[i];
        }
        return res^n;
    }
};