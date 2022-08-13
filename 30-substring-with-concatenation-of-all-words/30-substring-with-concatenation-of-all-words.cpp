class Solution {
    unordered_map<string, int> WordCount;
    int l, wL, substrSize, k;
    void helper(int i, string s, vector<int> &res){
        unordered_map<string, int> found;
        int used = 0;
        bool IsExceeded = false;
        
        for(int j=i;j<=l-wL;j+=wL){
            string str = s.substr(j,wL);
            if(WordCount.find(str)==WordCount.end()){
                found.clear();
                used = 0;
                IsExceeded = false;
                i = j+wL;
            }else{
                while(j-i==substrSize || IsExceeded){
                    string tmp = s.substr(i,wL);
                    i+=wL;
                    found[tmp]--;
                    if(found[tmp]>=WordCount[tmp])IsExceeded = false;
                    else used--;
                }
                
                found[str]++;
                if(found[str]<=WordCount[str])used++;
                else
                    IsExceeded = true;
                if(used==k && !IsExceeded)res.push_back(i);
            }
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        l = s.size();
        k = words.size();
        wL = words[0].size();
        substrSize = wL * k;
        for(string word: words){
            WordCount[word]++;
        }
        for(int i=0;i<wL;i++)
            helper(i,s,res);
        return res;
    }
};