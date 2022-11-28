class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int l = matches.size();
        unordered_map<int,int> losers;
        set<int> players, winners;
        for(int i=0;i<l;++i){
            players.insert(matches[i][0]);
            players.insert(matches[i][1]);
            
            winners.insert(matches[i][0]);
            losers[matches[i][1]]++;
        }
        
        vector<vector<int>> answer;
        
        vector<int> player(players.begin(),players.end());
        vector<int> temp;
        for(int i=0;i<player.size();++i){
            if(losers.find(player[i])==losers.end())
                temp.push_back(player[i]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp);
        temp.clear();
        for(auto loser:losers){
            if(loser.second==1)
            temp.push_back(loser.first);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp);
        return answer;
    }
};

/*
[[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
[1,2,3,5,5,4,4,4,10,10] winners
[3,3,6,6,7,5,8,9,4,9] losers->count exactly 1

[1,2,3,4,5,6,7,8,9,10] players
players - losers

**/