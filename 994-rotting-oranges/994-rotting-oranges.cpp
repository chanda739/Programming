class Solution {
public:
    int orangesRotting(vector<vector<int> > &A) {
        int n = A.size(), m = A[0].size();
        int fresh = 0, rotten = 0, minutes = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==2)
                    q.push({i,j});
                if(A[i][j]==1)
                    fresh++;
            }
        }

        if(fresh==0)
            return minutes;

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};
        pair<int,int> p;

        while(!q.empty()){
            minutes++;
            int sz = q.size();
            for(int j=0;j<sz;j++)
            {
                p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int a = p.first + x[i];
                    int b = p.second + y[i];
                    if(a<0 || a>=n || b<0 || b>=m || A[a][b]==0 || A[a][b]==2)continue;
                    A[a][b] = 2;
                    q.push({a,b});
                    fresh--;
                }
            }
        }
        return fresh==0?minutes-1:-1;
    }
};