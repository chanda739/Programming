class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        //using hashmap
        // set<int> st;
        // for(int i=0;i<nums.size();i++){
        //     if(st.find(nums[i])!=st.end())
        //         res.push_back(nums[i]);
        //     else
        //         st.insert(nums[i]);
        // }
        
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0)
                res.push_back(abs(nums[i]));
            else
                nums[abs(nums[i])-1] = -1 * nums[abs(nums[i])-1];
        }
        return res;
    }
};