class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> MorseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        for(string word: words){
            string temp = "";
            for(int i=0;i<word.size();++i){
                temp+=MorseCode[word[i]-'a'];
            }
            res.insert(temp);
        }
        return res.size();
    }
};