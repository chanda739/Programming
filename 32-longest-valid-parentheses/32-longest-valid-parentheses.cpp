class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.size(), res = 0;
        stack<int> st;
        for (int i = 0; i < l; i++) {
            if (s[i] == '(') 
                st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') 
                        st.pop();
                    else st.push(i);
                }
                else 
                    st.push(i);
            }
        }
        if (st.empty()) res = l;
        else {
            int i = l, j = 0;
            while (!st.empty()) 
            {
                j = st.top(); 
                st.pop();
                res = max(res, i-j-1);
                i = j;
            }
            res = max(res, i);
        }
        return res;
    }
};
