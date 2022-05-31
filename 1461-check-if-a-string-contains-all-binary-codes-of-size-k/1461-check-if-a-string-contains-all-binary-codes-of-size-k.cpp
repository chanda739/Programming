class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int l = s.size();
        set<string> st;
        if(l<k)
            return false;
        string tmp = "";
        
        for(int i=0;i<k;i++){
            tmp+=s[i];
        }
        st.insert(tmp);
        
        for(int i=k;i<l;i++){
            tmp+=s[i];
            tmp = tmp.substr(1,k);
            st.insert(tmp);
        }
        if(st.size()==pow(2,k))
            return true;
        return false;
    }
};

/*

00110110

00
01
11
10
01
10
*/