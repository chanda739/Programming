class Solution {
public:
    string reverseWords(string s) {
        vector<string> word;
        stringstream ss(s);
        string tmp,res="";
        while(ss>>tmp)word.push_back(tmp);
        
        for(int i=word.size()-1;i>=0;--i){
            if(i!=word.size()-1)res+=' ';
            res+=word[i];}
        return res;
    }
};