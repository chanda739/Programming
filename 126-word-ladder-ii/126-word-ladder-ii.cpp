class Solution {
    vector<vector<string>> res;
    vector<string> stack;
    unordered_map<string, int> mp;
    string begin;
public:
    void dfs(string word)
    {
        stack.push_back(word);
        if (word == begin)
        {
            vector<string> x = stack;
            reverse(x.begin(), x.end());
            res.push_back(x);
            stack.pop_back();
            return;
        }
        int cur = mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            for (char cc = 'a'; cc <= 'z'; cc++)
            {
                word[i] = cc;
                if (mp.count(word) && mp[word] == cur - 1)
                    dfs(word);
            }
            word[i] = c;
        }
        stack.pop_back();
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> set(wordList.begin(), wordList.end());
        begin = beginWord;
        queue<string> q;
        int k = beginWord.size();
        q.push(beginWord);
        mp[beginWord] = 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                string t = q.front();
                q.pop();
                int x = mp[t] + 1;
                for (int i = 0; i < k; i++)
                {
                    string temp = t;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;
                        if (!mp.count(temp) && set.count(temp))
                            mp[temp] = x, q.push(temp);
                    }
                }
            }
        }
        if (mp.count(endWord))
            dfs(endWord);
        return res;
    }
};