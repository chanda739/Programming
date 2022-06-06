class Solution {
public:
    bool CheckBit(int a, int j){
        if(a&(1<<j))
            return true;
        return false;
    }
    int singleNumber(vector<int>& nums) {
        int res = 0,count;
        for(int j=0;j<32;j++){
            count = 0;
            for(int i=0;i<nums.size();i++)
            {
                if(CheckBit(nums[i], j)){
                    count++;
                }
            }
            if(count%3==1){
                res = res|(1<<j);
            }
        }
        return res;
    }
};