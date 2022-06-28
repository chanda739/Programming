class Solution {
public:
    int minDeletions(string s) {
        vector<int> alphabet(26,0);
        for(auto x:s){
            alphabet[x-'a']++;
        }
        sort(alphabet.begin(), alphabet.end());
        int cnt = 0, t = 0;
        for(int i=24;i>=0;i--){
            if(alphabet[i]==0)break;
            
            if(alphabet[i] >= alphabet[i+1]){
                t = alphabet[i];
                alphabet[i] = max(0, alphabet[i+1]-1);
                cnt += t - alphabet[i];
            }
        }
        return cnt;
    }
};

/*
aab
baa
1 2
aaabbbcc
2 3 3
2 2 3
1 2 3
*/