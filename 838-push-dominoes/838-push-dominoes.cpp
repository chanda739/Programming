class Solution {
public:
    string pushDominoes(string dominoes) {
        int l = dominoes.size();
        vector<int> dp(l,0);
        
        int tmp = 0;
        for(int i=0;i<l;i++){
            if(dominoes[i]=='R')
                tmp = l;
            else if(dominoes[i]=='L')
                tmp = 0;
            else
                tmp = max(tmp-1, 0);
            dp[i]+=tmp;
        }
        
        tmp = 0;
        for(int i=l-1;i>=0;i--){
            if(dominoes[i]=='L')
                tmp = l;
            else if(dominoes[i]=='R')
                tmp = 0;
            else
                tmp = max(tmp-1, 0);
            dp[i]-=tmp;
        }
        string res = "";
        char ch;
        for(int x:dp){
            // if(x>0)ch='R';
            // else if(x<0)ch='L';
            // else ch = '.';
            // res.push_back(ch);
            res.push_back(x>0?'R':x<0?'L':'.');
        }
        return res;
    }
};