class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> st;
        for(auto x: words)
            st.insert(x);
        for(auto x: words){
            for(int i =1;i<x.size();i++)
            st.erase(x.substr(i));
        }
        int cnt = 0;
        for(auto word: st)
            cnt += word.size() + 1;
        return cnt;
    }
};