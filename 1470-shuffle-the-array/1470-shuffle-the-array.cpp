class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0,j=n,l=2*n,k=0;
        vector<int>shuffledNums(2*n,0);
        while(k<l){
            shuffledNums[k]= nums[i];
            shuffledNums[k+1] = nums[j];
            i++;
            j++;k=k+2;
        }
        return shuffledNums;
    }
};