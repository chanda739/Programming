class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int row = 0;row<numRows;++row){
            vector<int> triangle(row+1,1);
            for(int col = 1;col < row;++col){
                triangle[col] = res[row-1][col] + res[row-1][col-1];
            }
            res.push_back(triangle);
        }
        return res;
    }
};