class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = nums.size();
        if(l==1)return 0;
        vector<int> prefix(l,0);
        prefix[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        vector<int> prefixr(l,0);
        prefixr[l-1] = nums[l-1];
        for(int i=l-2;i>=0;i--){
            prefixr[i] = prefixr[i+1] + nums[i];
        }
        if(prefixr[1]==0)return 0;
        for(int i=1;i<l-1;i++){
            if(prefix[i-1]==prefixr[i+1])return i;
        }
        if(prefix[l-2]==0)return l-1;
        return -1;
    }
};