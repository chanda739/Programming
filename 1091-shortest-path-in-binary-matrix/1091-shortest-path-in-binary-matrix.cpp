class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>> &vis){
        return (i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && !vis[i][j]);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(),ans=0;
        vector<vector<bool>> vis(n,vector<bool> (n,false));
        queue<pair<int,int>> q;
        pair<int,int> p;
        
        if(grid[0][0]==0){
            vis[0][0] = true;
            q.push({0,0});
        }
        
        while(!q.empty()){
            int size = q.size();
            ans++;
            
            for(int a = 0;a<size;a++){
                p = q.front();q.pop();
                int i = p.first, j= p.second;
                
                if(i==n-1 && j==n-1)
                    return ans;
                for(int k = i-1;k<=i+1;k++){
                    for(int l = j-1;l<=j+1;l++){
                        if(isValid(grid,k,l,n,vis)){
                            vis[k][l] = true;
                            q.push({k,l});
                        }
                    }
                }
                
            }
        }
        return -1;
    }
};
/*
[[0,1],[1,0]]
[[1,0,0],[1,1,0],[1,1,0]]
[[0,0,0],[1,1,0],[1,1,0]]
*/