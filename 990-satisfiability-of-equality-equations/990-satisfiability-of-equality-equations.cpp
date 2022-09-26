class Solution {
public:
    int ch[26];
    int unionfind(int x){
        if(x!=ch[x])ch[x] = unionfind(ch[x]);
        return ch[x];
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)ch[i] = i;
        for(string equation : equations){
            if(equation[1]=='=')
                ch[unionfind(equation[0]-'a')] = unionfind(equation[3]-'a');
        }
        for(string equation : equations){
            if(equation[1]=='!' and unionfind(equation[0]-'a')==unionfind(equation[3]-'a'))
                return false;
        }
        return true;
    }
};