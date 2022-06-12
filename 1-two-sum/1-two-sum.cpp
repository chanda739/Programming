class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        O(n^2)
        O(nlogn)
        O(n)
        */
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
            }else{
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};