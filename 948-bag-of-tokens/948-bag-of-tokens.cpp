class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l = 0, h = tokens.size()-1;
        int score = 0, res = 0;
        while(l<=h and (power>=tokens[l] or score>0)){
            while(l<=h and power>=tokens[l]){
                score++;
                power-=tokens[l++];
            }
            
            res = max(res, score);
            
            if(l<=h and score>0){
                power+=tokens[h--];
                score--;
            }
        }
        return res;
    }
};

/**
if(power>=tokens[i])power-=tokens[i];score++;
if(power>=tokens[i] or score>0)power+=tokens[i];score--;
*/