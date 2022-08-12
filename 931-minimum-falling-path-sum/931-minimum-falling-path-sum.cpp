class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<n;++j){
                matrix[i][j] = matrix[i][j] + min(matrix[i+1][j],min(((j==0&&j!=n-1)?INT_MAX:matrix[i+1][j-1]),
                                                                 ((j!=0&&j==n-1)?INT_MAX:matrix[i+1][j+1])));
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++)
            res = min(res, matrix[0][i]);
        return res;
    }
};