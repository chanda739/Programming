class Solution {
public:
    int CountOccurence(int a, vector<int>& nums){
        int count = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]<=a)
                count++;
        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1, res = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            int n = CountOccurence(mid, nums);
            if(n>mid){
                res = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
};