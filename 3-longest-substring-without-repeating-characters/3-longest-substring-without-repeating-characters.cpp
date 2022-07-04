class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size(),j=0;
        int lls = 0,cnt=0;
        unordered_map<char, int> unique;
        for(int i=0;i<l;i++){
            if(unique.find(s[i])!=unique.end()){
                lls = max(lls, cnt);
                i = j;
                j = unique[s[i]] + 1;
                unique.clear();
                cnt = 0;    
            }else{
                unique[s[i]] = i;
                cnt++;  
            }
        }
        lls = max(lls, cnt);
        return lls;
    }
};