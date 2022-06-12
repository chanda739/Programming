class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i,j=0, l = nums.size(),sum = 0, maxScore = INT_MIN;
        set<int> unique;
        for(i=0;i<l;i++){
            while(unique.find(nums[i])!=unique.end()){
                unique.erase(nums[j]);
                sum = sum - nums[j];
                j++;
            }
            unique.insert(nums[i]);
            sum = sum + nums[i];
            maxScore = max(maxScore, sum);
        }
        return maxScore;
    }
};