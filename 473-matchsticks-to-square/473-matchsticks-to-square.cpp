class Solution {
    bool checkAllPossibilities(vector<int>& matchsticks,vector<bool> &visited, int side,int sum,int i,int k){
        if(k==1)return true;
        if(side==sum)return checkAllPossibilities(matchsticks,visited,side,0,0,k-1);
        for (int j = i; j < matchsticks.size(); j++) {
            if (visited[j] || sum + matchsticks[j] > side) continue;
            visited[j] = true;
            if (checkAllPossibilities(matchsticks, visited, side, sum + matchsticks[j], j+1, k)) return true;
            visited[j] = false;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int length = matchsticks.size();
        if(length<4)return false;
        int sum = std::accumulate(matchsticks.begin(), matchsticks.end(),0);
        if(sum%4!=0)return false;
        
        int sides = sum/4;
        vector<bool> visited(matchsticks.size(),false);
        return checkAllPossibilities(matchsticks,visited,sides,0,0,4);
    }
};