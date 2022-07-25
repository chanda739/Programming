class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1,mid;
        int left = -1, right = -1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                left = mid;
                hi = mid-1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                right = mid;
                lo = mid+1;
            }else if(nums[mid]<target){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        return {left,right};
    }
};