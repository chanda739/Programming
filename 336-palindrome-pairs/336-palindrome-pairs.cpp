class Solution {
public:
    bool isPalindrome(string &str, int i,int j){
        while(i<j){
            if(str[i++]!=str[j--])return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        int l = words.size();
        unordered_map<string, int> WordIndexMap;
        
        for(int i=0;i<l;++i)
            WordIndexMap[words[i]] = i;
        
        for(int i=0;i<l;++i){
            if(words[i]==""){
                for(int j=0;j<l;++j){
                    if(isPalindrome(words[j],0,words[j].size()-1) && i!=j){
                        res.push_back(vector<int>{i,j});
                        res.push_back(vector<int>{j,i});
                    }
                }
                continue;
            }
            //ssllss
            string str = words[i];
            reverse(str.begin(), str.end());
            if(WordIndexMap.find(str)!=WordIndexMap.end()){
                int idx = WordIndexMap[str];
                if(idx!=i){
                    res.push_back(vector<int>{i,idx});
                }
            }
            
            for (int j = 1; j < str.size(); j++) {
                if (isPalindrome(str, 0, j-1)) {
                    string s = str.substr(j, str.size()-j);
                    if (WordIndexMap.find(s) != WordIndexMap.end())
                        res.push_back(vector<int>{i, WordIndexMap[s]});
                }
                if (isPalindrome(str, j, str.size()-1)) {
                    string s = str.substr(0, j);
                    if (WordIndexMap.find(s) != WordIndexMap.end())
                        res.push_back(vector<int>{WordIndexMap[s], i});
                }
            }
        }
        return res;
    }
};