class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int res = -1, i=0, j = 0,sum = 0, tot = 0;
        for(int k = 0;k<nums.size();k++)
            sum += nums[k];
        sum = sum - x;
        if(sum<0)
            return -1;
        if(sum==0)
            return nums.size();
        while(j<nums.size()){
            if(tot < sum)
                tot += nums[j];
            while(tot >= sum){
                if(tot == sum)
                    res = max(res, j-i+1);
                tot -=nums[i++];
            }
            j++;
        }
        return res==-1?-1:nums.size() - res;
    }
};
