class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> st;
        q.push(start);
        st.insert(start);
        int mut = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                string node = q.front();
                q.pop();
                
                if(node==end)return mut;
                
                for(char ch:"ACGT"){
                    for(int j=0;j<node.size();j++){
                        string nxt = node;
                        nxt[j] = ch;
                        if(!st.count(nxt) and find(bank.begin(), bank.end(), nxt)!=bank.end()){
                            q.push(nxt);
                            st.insert(nxt);
                        }
                    }
                }
            }
            mut++;
        }
        return -1;
    }
};