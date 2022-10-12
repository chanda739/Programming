class Solution {
public:
    //COndition to form a triangle a+b > c
    //Perimeter = a + b + c
    int largestPerimeter(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=sz-1;i>1;i--){
            if(nums[i]<(nums[i-1]+nums[i-2]))
                return nums[i] + nums[i-1] + nums[i-2];
        }
        return 0;
    }
};