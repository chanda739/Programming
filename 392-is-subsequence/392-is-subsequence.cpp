class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.size(), tl = t.size(),is = 0, it = 0;
        if(sl>tl)return false;
        while(is<sl and it<tl){
            if(s[is]==t[it]){
                is++;it++;
            }else it++;
        }
        if(is==sl)return true;
        return false;
    }
};