class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        for(int row = 0;row<=rowIndex;++row){
            vector<int> triangle(row+1,1);
            for(int col = 1;col < row;++col){
                triangle[col] = res[row-1][col] + res[row-1][col-1];
            }
            res.push_back(triangle);
        }
        return res[rowIndex];
    }
};