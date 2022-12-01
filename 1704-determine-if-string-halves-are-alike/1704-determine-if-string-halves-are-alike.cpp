class Solution {
public:
    bool halvesAreAlike(string s) {
        int l = s.size();
        int count = 0;
        char c;
        for(int i=0;i<l/2;++i){
            c = s[i];
            char isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            char isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
            if(isLowercaseVowel|| isUppercaseVowel)
                count++;
        }
        for(int i=l/2;i<l;++i){
            c = s[i];
            char isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            char isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
            if(isLowercaseVowel|| isUppercaseVowel)
                count--;
        }
        return count==0?true:false;
    }
};