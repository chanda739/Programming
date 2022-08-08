class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
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
    }
};