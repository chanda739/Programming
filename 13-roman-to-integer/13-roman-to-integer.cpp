class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapping = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int res = mapping[s.back()];
        for(int i=s.size()-2;i>=0;--i){
            if(mapping[s[i]]<mapping[s[i+1]])
                res-=mapping[s[i]];
            else
                res+=mapping[s[i]];
        }
        return res;
    }
};