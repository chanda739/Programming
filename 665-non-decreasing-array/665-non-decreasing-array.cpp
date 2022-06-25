class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0,mini;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(cnt==1)return false;
                cnt++;
                if(i<2 || nums[i-2]<=nums[i])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;;
    }
};
/**
3 4 2 3
//Approach Failed because of comparing adjacent elements
 bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])cnt++;
        }
        return cnt<=1?true:false;
    }

If we found a pair where nums[i-1] > nums[i], we can perform one of two operations,
Changes nums[i-1] to nums[i], when nums[i-2] <= nums[i] .
Changes nums[i] to nums[i-1], when the above case is not true.
**/
