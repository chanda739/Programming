class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size(),i,j,t;
        vector<vector<int>> Transposematrix(n, vector<int> (m,0));
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                Transposematrix[j][i] = matrix[i][j];
            }
        }
        
        return Transposematrix;
    }
};