class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if (stamp == target) 
            return {0};
        
        int slen = stamp.size(), tlen = target.size() - slen + 1, i, j;
        vector<int> res;
        bool tdiff = true, sdiff;
        while (tdiff)
            for (i = 0, tdiff = false; i < target.size(); i++) {
                for (j = 0, sdiff = false; j < stamp.size(); j++)
                    if (target[i+j] == '*') continue;
                    else if (target[i+j] != stamp[j]) break;
                    else sdiff = true;
                if (j == slen && sdiff) {
                    for (j = i, tdiff = true; j < slen + i; j++)
                        target[j] = '*';
                    res.push_back(i);
                }
            }
        for (i = 0; i < target.size(); i++) if (target[i] != '*') return {};
        reverse(res.begin(), res.end());
        return res;
    }
};