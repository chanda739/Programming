class Solution {
public:
    void combinationSum3Util(int k, int n,set<vector<int>> &sortedset, vector<int> &cmb){
        if(cmb.size()==k && n==0){
            sortedset.insert(cmb);
        }
        for(int i = cmb.size()==0?1:cmb.back()+1;i<=9;i++){
            cmb.push_back(i);
            combinationSum3Util(k,n-i,sortedset,cmb);
            cmb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cmb;
        set<vector<int>> sortedset;
        combinationSum3Util(k,n,sortedset,cmb);
        for(auto x: sortedset)
            res.push_back(x);
        return res;
    }
};