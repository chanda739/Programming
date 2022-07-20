struct Node {
    const string& word;
    int index;
    Node(const string &word, int index) : word(word), index(index) {}
};
class Solution {
public:
    int numMatchingSubseq(const string& s, vector<string>& words) {
        vector<Node> buckets[26];
        for (string& word : words) {
            char startingChar = word[0];
            buckets[startingChar-'a'].emplace_back(word, 0);
        }
        int ans = 0;
        for (char c : s) {
            auto currBucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            for (Node& node : currBucket) {
                ++node.index; // Point to next character of node.word
                if (node.index == node.word.size()) {
                    ++ans;
                } else {
                    buckets[node.word[node.index]-'a'].push_back(node);
                }
            }
        }
        return ans;
    }
};
/*TLE O(5000 * 50000)
class Solution {
    int isSubsequence(string &s, int is, int ls, string word, int iw, int lw){
        if(is==ls && iw<lw)return 0;
        if(iw==lw)return 1;
        if(s[is]==word[iw]){
            return isSubsequence(s,is+1,ls,word,iw+1,lw);
        }else{
            return isSubsequence(s,is+1,ls,word,iw,lw);
        }
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int countSubseq = 0;
        
        for(int i=0;i<words.size();i++){
            countSubseq+= isSubsequence(s,0,s.size(),words[i],0,words[i].size());
        }
        return countSubseq;
    }
};*/