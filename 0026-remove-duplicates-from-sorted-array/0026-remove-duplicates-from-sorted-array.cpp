class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=1,l=nums.size(),i;
        //[0,0,1,1,1,2,2,3,3,4]
        for(i=1;i<l;i++){
            if(nums[i]!=nums[i-1]){
                nums[p++]=nums[i];
            }
        }
        return p;
    }
};
