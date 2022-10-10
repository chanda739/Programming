class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i=0,l = palindrome.size();
        string res = palindrome;
        for(i=0;i<l/2;i++){
            if(res[i]!='a'){res[i] = 'a';return res;}
        }
        res[l-1] = 'b';
        return l==1?"":res;
    }
};