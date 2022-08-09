class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return 0;
        int res = 0,count=0,diff=nums[1]-nums[0],curr;
        for(int i=1;i<n-1;i++){
            //curr = nums[i+1]-nums[i];
            //if(diff == curr){
            if((nums[i]-nums[i-1]) == (nums[i+1]-nums[i])){
                count++;
            }else{
               // diff = curr;
                count = 0;
            }
            res+=count;
        }
        return res;
    }
};

/*
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n<3)return 0;
        int res = 0,count=0,diff=nums[1]-nums[0],curr;
        for(int i=1;i<n-1;i++){
            curr = nums[i+1]-nums[i];
            if(diff == curr){
                count++;
            }else{
                diff = curr;
                count = 0;
            }
            res+=count;
        }
        return res;
    }
};
**/