class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        int s = 0,count = 0;
        for(int x:nums){
            if(x)count = 0;
            else{
                count++;
            }
            sum+=count;
        }
        return sum;
    }
};