class Solution {
    bool helper(string s, unordered_set<string>& wordDict){
        if(wordDict.size()==0)return false;
        int l = s.size();
        vector<bool> dp(l+1,false);
        dp[0] = true;//empty string
        for(int i=1;i<=l;++i){
            for(int j=i-1;j>=0;--j){
                if(dp[j]==true){
                    string word = s.substr(j,i-j);
                    if(wordDict.find(word)!=wordDict.end()){
                        dp[i] = true; break;
                    }
                }
            }
        }
        return dp[l];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string st:wordDict)
            dict.insert(st);
        return helper(s,dict);
    }
};