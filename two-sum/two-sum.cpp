class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pairs;
        for(int i=0;i<nums.size();i++){
            if(pairs.find(target-nums[i])!=pairs.end()){
                return {pairs[target-nums[i]], i};
            }else{
                pairs[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};