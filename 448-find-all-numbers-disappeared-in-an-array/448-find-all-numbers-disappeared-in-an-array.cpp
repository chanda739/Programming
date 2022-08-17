class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int n = nums.size();
        vector<int> res;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end())
                res.push_back(i);
        }
        return res;
    }
};