class Solution {
    int count = 0;
public:
    int maxAreaOfIslandHelper(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)return 0;
        grid[i][j] = 0;
        count++;
        maxAreaOfIslandHelper(grid,i-1,j,m,n);
        maxAreaOfIslandHelper(grid,i,j-1,m,n);
        maxAreaOfIslandHelper(grid,i+1,j,m,n);
        maxAreaOfIslandHelper(grid,i,j+1,m,n);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                count = 0;
                islands = max(islands, maxAreaOfIslandHelper(grid,i,j,m,n));
            }
        }
        return islands;
    }
};