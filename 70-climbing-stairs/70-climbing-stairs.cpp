class Solution {
public:
    int climbStairs(int n) {
        if(n<3)return n;
        vector<long> Ways(n+1);
        Ways[0] = 0;Ways[1] = 1;Ways[2] = 2;
        for(int i=3;i<=n;i++){
            Ways[i] = Ways[i-1] + Ways[i-2];
        }
        return Ways[n];
    }
};