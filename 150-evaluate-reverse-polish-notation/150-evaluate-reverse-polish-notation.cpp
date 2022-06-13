class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = 0 , l = tokens.size(), a,b;
        stack<int> st;
        while(i<l){
                if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                    a = st.top();st.pop();
                    b = st.top();st.pop();
                    if(tokens[i]=="+")st.push(b+a);
                    else if(tokens[i]=="-")st.push(b-a);
                    else if(tokens[i]=="*")st.push(b*a);
                    else if(tokens[i]=="/")st.push(b/a);
                }
                else
                    st.push(stoi(tokens[i]));
            i++;
        }
        return !st.empty()?st.top():-1;
    }
};