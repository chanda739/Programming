class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
        */
        int l = nums.size();
        k = k%l;
        reverse(nums.begin(),nums.end());//[7,6,5,4,3,2,1]
        reverse(nums.begin(),nums.begin()+k);//[5,6,7,4,3,2,1]
        reverse(nums.begin()+k,nums.end());//[5,6,7,1,2,3,4]
    }
};