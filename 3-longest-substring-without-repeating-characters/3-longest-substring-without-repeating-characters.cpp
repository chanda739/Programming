class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length(),i=0,j=0,res=0,SubstringLen=0;
        unordered_map<char,int> mp;
        //maintain 2 pointer, one to start of the substring and other to the end of substring
        //initially both starts from 0th index
        while(j<l){
            //Check if the character exists in the map, if not then insert and increment count
            //if exits in the map then get longest string length and reset count and starting index of substring
            if(mp.find(s[j])!=mp.end()){
                res = max(res, SubstringLen);
                j=i;
                i = mp[s[j]] + 1;
                SubstringLen = 0;
                mp.clear();
            }
            else{
                mp[s[j]] = j;
                SubstringLen++;
            }
            j++;
        }
        res = max(res,SubstringLen);
        return res;
    }
};