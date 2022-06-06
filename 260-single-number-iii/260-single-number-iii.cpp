class Solution {
public:
    int CheckBit(int a){
        int bit =0,i=0;
        for(int i=0;i<32;i++)
        {
            int num=1<<i;
            if((a&num))
            {
                bit=i;
                break;
            }
        }
        return bit;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int first=0, second=0,res=0;
        
        for(int i=0;i<nums.size();i++){
            res^=nums[i];//xor of first and second
        }
        //split first and second using set bit and unset bit
        int bit = CheckBit(res);
        bit = 1<<bit;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&bit)
                first^=nums[i];
            else
                second^=nums[i];
        }
        return {first,second};
    }
};
//[-145417756,744132272]