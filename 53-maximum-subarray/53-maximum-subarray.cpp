class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxSum=INT_MIN,l=nums.size(),i;
        //Kadane's algorithm
        for(i=0;i<l;i++){
            sum+=nums[i];
            if(sum>maxSum){
                maxSum = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
    }
};