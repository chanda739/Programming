class Solution {
public:
    bool isVowel(char c){
        bool isLowercaseVowel, isUppercaseVowel;
        isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
        return isLowercaseVowel || isUppercaseVowel;
    }
    string reverseVowels(string s) {
        int l = s.size(),i=0,j=l-1;
        while(i<j){
            while(i<j and !isVowel(s[i]))i++;
            while(i<j and j>0 and !isVowel(s[j]))j--;
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};