class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int l = nums.size();
        vector<int> zeroPerm(l,0);
        for(int i=0;i<l;i++){
            zeroPerm[i] = nums[nums[i]];
        }
        return zeroPerm;
    }
};