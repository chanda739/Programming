class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums.size();
        int mSum = INT_MIN, sum = 0;
        for(int x:nums){
            sum+=x;
            if(mSum<sum)mSum = sum;
            if(sum<0)sum = 0;
        }
        return mSum;
    }
};