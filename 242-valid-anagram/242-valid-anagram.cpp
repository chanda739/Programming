class Solution {
public:
    bool isAnagram(string s, string t) {
        /*O(nlogn)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return t==s;
        */
        /*O(n)*/
        unordered_map<char, int> anagram;
        for(char ch:s)anagram[ch]++;
        
        for(char ch:t){
            if(anagram.find(ch)==anagram.end())return false;
            else{
                anagram[ch]--;
                if(anagram[ch]==0){
                    anagram.erase(ch);
                }
            }
        }
        return anagram.empty()?true:false;
    }
};