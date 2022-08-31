/**/
class Solution {
public:
    int m,n;
    vector<vector<int>> res;
    vector<vector<bool>> visitPacific,visitAtlantic;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>&visit, int i, int j){
        if(visit[i][j])return;
        visit[i][j] = true;
        if(visitPacific[i][j]&& visitAtlantic[i][j])
            res.push_back(vector<int>{i,j});
        
        if(i+1<m &&heights[i+1][j]>=heights[i][j])dfs(heights,visit,i+1,j);
        if(i-1>=0 &&heights[i-1][j]>=heights[i][j])dfs(heights,visit,i-1,j);
        if(j+1<n &&heights[i][j+1]>=heights[i][j])dfs(heights,visit,i,j+1);
        if(j-1>=0 && heights[i][j-1]>=heights[i][j])dfs(heights,visit,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(!size(heights))return res;
        m = heights.size(), n = heights[0].size();
        visitPacific = visitAtlantic = vector<vector<bool>>(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(heights,visitPacific, i,0),
            dfs(heights,visitAtlantic, i, n-1);
        }
        for(int i=0;i<n;i++){
            dfs(heights,visitPacific,0, i),
            dfs(heights,visitAtlantic, m-1, i);
        }
        return res;
    }
};
