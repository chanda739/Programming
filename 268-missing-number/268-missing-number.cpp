class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0;
        for(int i=0;i<nums.size();i++){
            missing = missing ^ nums[i] ^ (i+1);
        }
        return missing;
    }
};
