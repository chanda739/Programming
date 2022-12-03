class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> characters;
        for(char ch:s)characters[ch]++;
        
        set<pair<int,char>> pq;
        for (auto[character,count] : characters) pq.insert({-count, character});
        
        string res = "";
        for(auto [count, character] : pq)
            res+= string(-count, character);
        return res;
    }
};