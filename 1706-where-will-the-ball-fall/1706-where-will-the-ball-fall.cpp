class Solution {
public:
    int findBallUtil(vector<vector<int>>& grid, int i, int j){
        if(i==grid.size())return j;
        int col = j + grid[i][j];

        if(col<0 or col>grid[0].size()-1 or  grid[i][j]!=grid[i][col])
            return -1;
        return findBallUtil(grid, i+1,col);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n,0);
        
        for(int i=0;i<n;i++)
            res[i] = findBallUtil(grid, 0, i);
        
        return res;        
    }
};