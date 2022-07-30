class Solution {
    vector<int> count(string st){
        vector<int> res(26);
        for(char ch:st)res[ch-'a']++;
        return res;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> words2max(26), aCount(26);
        int i;
        for(string word2: words2){
            aCount = count(word2);
            for(int i=0;i<26;i++)
                words2max[i] = max(words2max[i], aCount[i]);
        }
        for (string word1 : words1) {
            aCount = count(word1);
            for (i = 0; i < 26; ++i)
                if (aCount[i] < words2max[i])
                    break;
            if(i==26)res.push_back(word1);
        }
        return res;
    }
};


