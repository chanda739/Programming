class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},col[9][9]={0},sub[9][9]={0};
        
        int k,l;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='.'){
                    l=board[i][j]-'0'-1;
                    k=i/3*3+j/3;
                    if(row[i][l]||col[j][l]||sub[k][l])
                        return false;
                    row[i][l]=col[j][l]=sub[k][l]=1;
                }
            }
        }
        return true;
    }
};