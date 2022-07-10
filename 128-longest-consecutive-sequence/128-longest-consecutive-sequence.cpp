class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int lcs = 1, j=1,l = nums.size(),i=0;
        sort(nums.begin(),nums.end());
        for(i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
            if(nums[i]==nums[i-1]+1)j++;
            else{
                lcs = max(lcs, j);
                j = 1;
            }}
        }
        lcs = max(lcs, j);
        return l==0?0:lcs;
        
       //  if(nums.size()<=1)return nums.size();
       // // unordered_set<int> s(nums.begin(),nums.end());
       //  unordered_set<int> s;
       //  for(int i : nums)s.insert(i);
       //  int lcs = 0;
       //  for(int i=0;i<nums.size();i++){
       //      if(s.find(nums[i]-1)==s.end()){
       //          int tmp = nums[i];
       //          while(s.find(tmp)!=s.end())tmp++;
       //          lcs = max(lcs, tmp - nums[i]);
       //      }
       //  }
       //  return lcs;
        /*
        //TC: O(nlogn)
        sort(nums.begin(), nums.end());
        int lcs = 0, ccs = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==(1+nums[i-1]))
                ccs++;
            else{
                lcs = max(lcs, ccs);
                ccs = 0;
            }
        }
        lcs = max(lcs, ccs);
        return lcs+1;
        //Fails for input [1,2,0,1]
        */
    }
};
//0 1 2 3 4 100 200