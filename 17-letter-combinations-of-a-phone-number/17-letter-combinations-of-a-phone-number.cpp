class Solution {
public:
    void letterCombinationsUtil(string digits, int N,int pos, unordered_map<char,string> &Letter, string &st, vector<string> &res){
        if(pos==N){
            res.push_back(st);
            return;
        }
        string t = Letter[digits[pos]];
        for(int i=0;i<t.size();i++){
            st.push_back(t[i]);
            letterCombinationsUtil(digits,digits.size(),pos+1,Letter,st,res);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
         vector<string> res;
    unordered_map<char,string> Letter;
    if(digits.size()==0)
        return res;
    //Letter['0'] = "0";Letter['1'] = "1";
    Letter['2'] = "abc";Letter['3'] = "def";
    Letter['4'] = "ghi";Letter['5'] = "jkl";Letter['6'] = "mno";
    Letter['7'] = "pqrs";Letter['8'] = "tuv";Letter['9'] = "wxyz";
    string st="";
    letterCombinationsUtil(digits,digits.size(),0,Letter,st,res);
    return res;
    }
};