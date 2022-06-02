class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size(), i = 0, j= n-1,k=0;
        while(k<=j){
            if(nums[k]==0 && i!=k){
                swap(nums[i], nums[k]);
                i++;
            }
            else if(nums[k]==2 && j!=k){
                swap(nums[j], nums[k]);
                j--;
            }
            else
                k++;
        }
        //using counting sort logic
        // int color[3] = {0};
        // for(int i=0;i<n;i++){
        //     color[nums[i]]++;
        // }
        // int j = 0;
        // for(int i=0;i<n;){
        //     while(j<3 && color[j]>0){
        //         nums[i++] = j;
        //         color[j]--;
        //     }
        //     j++;
        // }
    }
};
