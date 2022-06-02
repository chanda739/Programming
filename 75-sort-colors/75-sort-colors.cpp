class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        //using counting sort logic
        int color[3] = {0};
        for(int i=0;i<n;i++){
            color[nums[i]]++;
        }
        int j = 0;
        for(int i=0;i<n;){
            while(j<3 && color[j]>0){
                nums[i++] = j;
                color[j]--;
            }
            j++;
        }
    }
};