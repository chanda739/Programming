class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i=INT_MAX,j=INT_MAX,k;
        for(auto n:nums){
            if(n<i)i=n;
            else if(i<n and n<j)j=n;
            else if(j<n)return true;
        }
        return false;
    }
};