class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int l = triangle.size(),i,j=0;
        //Bottom up approach
        for(i=l-2;i>=0;i--){
            for(j=0;j<=i;j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};