class Solution {
public:
    void dfs(int n, int i, int k, vector<int> &res){
        if(n==0){
            res.push_back(i);
            return;
        }
        vector<int> nextDigit;
        int tailDigit = i%10;
        nextDigit.push_back(tailDigit+k);
        if(k!=0)nextDigit.push_back(tailDigit-k);
        for(int nd :nextDigit){
            if(0<=nd && nd<10){
                dfs(n-1, i*10+nd,k,res);
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1)return {0,1,2,3,4,5,6,7,8,9};
        
        vector<int> res;
        for(int i=1;i<10;i++)
            dfs(n-1,i,k,res);
        
        return res;
    }
};