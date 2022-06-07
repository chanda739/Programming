class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int l = nums.size(),count=0,t;
        unordered_map<int,int> HashM;
        for(int i=0;i<l;i++){
            HashM[nums[i]]++;
        }
        for(auto x: HashM){
            if(x.second>1){
                t = x.second;
                count += t*(t-1)/2;
            }
        }
        return count;
    }
};