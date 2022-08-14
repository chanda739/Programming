class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> List(wordList.begin(), wordList.end());
        if(List.find(endWord)==List.end())return 0;//endWord is not present in wordList, so no such sequence exists
        queue<string> q;
        q.push(beginWord);
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int stfs = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;++i){
                string word = q.front();
                q.pop();
                if(word==endWord)return stfs;
                
                for(int j=0;j<word.size();++j){
                    for(char ch='a';ch<='z';++ch){
                        string str = word;
                        str[j] = ch;
                        if(List.find(str)!=List.end() and visited.find(str)==visited.end()){
                            q.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            stfs++;
        }
        return 0;
    }
};