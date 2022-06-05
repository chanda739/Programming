class Solution {
public:
    bool AllPossibleNQueenPlacement(vector<vector<int> > &res,vector<int> &curr,int A,int row,vector<bool>                                          &col,vector<bool>&leftd,vector<bool>&rightd)
    {
        if(row==A){
            res.push_back(curr);
            return true;
        }
        for(int c=0;c<A;c++){
            if(col[c]==false && leftd[row-c+A-1]==false && rightd[row+c]==false)
            {    
                curr.push_back(c);
                //res[row][c] = 1;//'Q';
                col[c] = true;
                leftd[row-c+A-1] = true;
                rightd[row+c] = true;
                AllPossibleNQueenPlacement(res,curr,A,row+1,col,leftd,rightd);
               curr.pop_back();
               // res[row][c] = 0;//'.';
                col[c] = false;
                leftd[row-c+A-1] = false;
                rightd[row+c] = false;
            }
        }
        return false;
    }
    int totalNQueens(int n){
        vector<vector<int> > res;//(A,vector<int>(A,0));
        vector<bool> col(n,false),leftd(2*n-1,false),rightd(2*n-1,false);
        vector<int> curr;
        AllPossibleNQueenPlacement(res,curr,n,0,col,leftd,rightd);
        return res.size();
    }
};



