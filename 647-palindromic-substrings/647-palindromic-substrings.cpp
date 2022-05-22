class Solution {
public:
   // int res = 1;
    int isPalindrome(string s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;i--;j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        if(s.size()<1)
            return 0;
        int l = s.size(), res= 0;
        
        for(int i=0;i<l;i++){
            res+=isPalindrome(s,i,i);
            res+=isPalindrome(s,i,i+1);
        }
        return res;
    }
};