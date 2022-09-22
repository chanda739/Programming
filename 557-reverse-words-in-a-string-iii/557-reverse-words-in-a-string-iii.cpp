class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0,k=0,l = s.size();
        while(j<l){
            while(j<l and s[j]!=' ')j++;
            k = j-1;
            while(i<=k){
                char ch = s[i];s[i] = s[k];s[k] = ch;
                i++;k--;
            }
            i = j+1;j++;
        }
        k = j-1;
        while(i<=k){
            char ch = s[i];s[i] = s[k];s[k] = ch;
            i++;k--;
        }
        return s;
    }
};