class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        for(j=0;j<nums.size();j++){
            if(nums[j]==0)continue;
            else{
                swap(nums[i],nums[j]);i++;
            }
        }
    }
};