class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(nums.size(),0);
        int sum = 0;
        for(int x:nums)
            if(x%2==0)
                sum+=x;
        for(int i=0;i<queries.size();i++){
            int v = queries[i][0], ind = queries[i][1];
            if(nums[ind]%2==0)sum-=nums[ind];
            nums[ind]+=v;
            if(nums[ind]%2==0)sum+=nums[ind];
            res[i] = sum;
        }
        return res;
    }
};