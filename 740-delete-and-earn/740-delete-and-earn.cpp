class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int l = 10001;
        vector<int> total(l,0),res(l,0);
        
        //get sum of each element in the given array
        for(int i=0;i<nums.size();i++)
            total[nums[i]]+=nums[i];
        
        res[0] = 0;
        res[1] = total[1];
        for(int i=2;i<l;i++){
            res[i] = max(res[i-2]+total[i],res[i-1]);
            //add the current element and skip the element consecutive to it or skip the current element
            //include or exclude
        }
        return res[l-1];
    }
};