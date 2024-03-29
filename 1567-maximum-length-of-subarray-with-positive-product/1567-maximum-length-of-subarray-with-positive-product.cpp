class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int framestart = -1, firstneg = -2, longest = 0, neg = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 0) // reset everytime if zero
            {  
                neg = 0;framestart = i;firstneg = -2;
            } 
            else 
            {
                if (nums[i] < 0) neg++;  // number of negatives in  current frame means (frame excluding zero)
                if (neg == 1 && firstneg == -2) firstneg = i;   // init firstneg cnt neg;
                if (neg % 2 == 0) longest = max(longest, i - framestart);  //if curr cnt neg is framestart;
                else longest = max(longest, i - firstneg);  // first firstneg after last zero;
            }
        }
        return longest;
    }
};