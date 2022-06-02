class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end())
                res.push_back(nums[i]);
            else
                st.insert(nums[i]);
        }
        return res;
    }
};