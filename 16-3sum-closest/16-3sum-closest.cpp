class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l = nums.size(), closest = 0;
        if(l<3)return 0;
        sort(nums.begin(), nums.end());
        closest = nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<l-2;++i){
            if(i>0 and nums[i]==nums[i-1])continue;
            int j = i+1,k = l-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target)return sum;
                if(abs(target-sum)<abs(target-closest))closest = sum;
                if(sum<target)j++;
                else if(sum>target)k--;
            }
        }
        return closest;
    }
};