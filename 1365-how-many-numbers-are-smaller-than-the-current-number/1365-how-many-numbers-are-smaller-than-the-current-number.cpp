class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count;
        int l = nums.size(),temp;
        for(int i=0;i<l;i++){
            temp=0;
            for(int j=0;j<l;j++){
                if(i!=j&&nums[i]>nums[j])
                    temp++;
            }
            count.push_back(temp);
        }
        return count;
    }
};