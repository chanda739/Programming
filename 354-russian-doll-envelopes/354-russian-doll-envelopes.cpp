class Solution {
public:
    static bool comp(vector<int> &e1, vector<int> &e2){
        //inc order of height and when height same then descending order of width
        if(e1[0]==e2[0])
            return e1[1]>e2[1];        
        return e1[0]<e2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int N = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> res;
        for(int i=0;i<N;i++){
            int x = envelopes[i][1];
            int id = lower_bound(res.begin(), res.end(), x) - res.begin();
            
            if(id>=res.size())res.push_back(x);
            else
                res[id] = x;
        }
        
    return res.size();
    }
};

/*
5 6 6 2
4 4 7 3
[[46,89],[50,53],[52,68],[72,45],[77,81]]
3

int l = A.size();
    vector<int> dp(l,0);
    dp[0] = 1;
    for(int i=1;i<l;i++){
        int ans = INT_MIN;
        for(int j=0;j<i;j++){
            if(A[j] < A[i])
                ans = max(ans, dp[j]);
        }
        if(ans==INT_MIN)
            dp[i] = 1;
        else
            dp[i] = ans + 1;
    }
    int res = INT_MIN;
    for(int i=0;i<l;i++){
        res = max(res, dp[i]);
    }
    return res;
*/