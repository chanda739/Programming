class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else if(!iswalnum(s[i]))i++;
            else if(!iswalnum(s[j]))j--;
            else
                return false;
        }
        return true;
    }
};