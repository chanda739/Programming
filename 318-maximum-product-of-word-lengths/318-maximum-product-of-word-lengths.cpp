class Solution {
public:
    int maxProduct(vector<string>& words) {
        int N = words.size(), res = 0;
        vector<int> letter(N);
        for(int i=0;i<N;i++){
            for(auto ch : words[i]){
                letter[i] |= 1 << (ch-'a');
            }
            for(int j = 0; j< i;j++){
                if((letter[i]&letter[j])==0)
                    res = max(res, int(size(words[i])*size(words[j])));
            }
        }
        return res;
    }
};