class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool alphabet[26] ={false};
        int l = sentence.size();
        if(l<26)return false;
        
        for(int i=0;i<l;i++){
            alphabet[sentence[i]-'a'] = true;
        }
        for(int i=0;i<26;i++)
            if(alphabet[i]==false)return false;
        return true;
    }
};