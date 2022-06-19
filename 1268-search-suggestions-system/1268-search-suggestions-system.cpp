class Trie{
  const static int ALPHABET_SIZE = 26;
    struct trieNode {
        vector<trieNode*> t{vector<trieNode*>(ALPHABET_SIZE, NULL)};
        bool isWord = false;
    }*root, *curr;
    void dfs(trieNode* curr, string& word, vector<string> &res){
        if(res.size()==3)return;
        if(curr->isWord==true)res.push_back(word);
        
        for(char c='a';c<='z';c++){
            if (curr -> t[c - 'a'] != NULL){
                word+= c;
                dfs(curr -> t[c - 'a'], word, res);
                word.pop_back();
            }
        }
    }
    public:
        Trie(){
            root = new trieNode();
        }
        // Function to insert new word in trie 
        void insert(string key) {
            curr = root;
            // Iterate for the length of a word 
            for (int i = 0; i < key.length(); i++) {
                // If the next key does not contains the character 
                if (curr -> t[key[i] - 'a'] == NULL)
                    curr -> t[key[i] - 'a'] = new trieNode();
                curr = curr -> t[key[i] - 'a'];
            }
            // isWord 
            curr -> isWord = true;
        }
    
    // Search function to find a word of a sentence 
    vector<string> getWordsStartingWith(string word) {
        curr = root;
        vector<string> res;
        // Iterate for the complete length of the word 
        for (int i = 0; i < word.length(); i++) {
            // If the character is not present then word 
            // is also not present 
            if (curr -> t[word[i] - 'a'] == NULL)
                return res;
            // If present move to next charater in Trie 
            curr = curr -> t[word[i] - 'a'];
        }
        dfs(curr, word, res);
        return res;
    }  
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for (auto x: products)
            trie.insert(x);
        vector < vector<string> > ans;
        string prefix;
        for (char x: searchWord) {
            prefix+=x;
            ans.push_back(trie.getWordsStartingWith(prefix));
        }
        return ans;
    }
};