class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        1. insert elements to set and return element if it is found in set O(n) TC and O(n) SC
        2. Same can be done using map
        3. As given element are in range[1,n], replace element at ith index to i+1 and traverse again
        4. XOR all array elements with elements in range[1,n]. Doesn't work as a element can repeat multiple times
        */
       /* int res = 0, i=0;
        for(int i=0;i<nums.size();i++)
            res = res ^ nums[i] ^ i;
        return res;
        */
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
        while(slow!=fast){
             slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/***
Floyd's Tortoise and Hare (Cycle Detection)
**/