class Solution {
    int isPalindrome(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
                i--;j++;
        }
        return j - i - 1;
    }
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        int st = 0, end = 0;
        
        for(int i=0;i<s.size();++i){
           int odd = isPalindrome(s,i,i);
            int even = isPalindrome(s,i,i+1);
            int len = max(odd, even);
            if(len > (end-st)){
                st = i - (len-1)/2;
                end = i + (len)/2;
            }
        }
        int l = end-st+1;
        return s.substr(st,l);
    }
};