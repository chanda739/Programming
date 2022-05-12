class Solution {
public:
    void swap(int&a,int&b){
        int t = a;
        a=b;
        b=t;
    }
    void permuteUtil(vector<int> &A,int N, int pos,set<vector<int>>&res){
        if(pos==N-1){
            res.insert(A);
            return;
        }
        else{
            for(int i=pos;i<N;i++){
                swap(A[i],A[pos]);
                permuteUtil(A,N,pos+1,res);
                swap(A[i],A[pos]);
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        set<vector<int>> st;
        permuteUtil(nums,nums.size(),0,st);
        for(auto x : st)
            res.push_back(x);
        return res;
    }
};