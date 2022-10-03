class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ttime = 0, mtime = 0;
        for(int i=0;i<colors.size();i++){
            if(i>0 and colors[i]!=colors[i-1])mtime = 0;
            
            ttime +=min(mtime, neededTime[i]);
            mtime = max(mtime, neededTime[i]);
        }
        return ttime;
    }
};