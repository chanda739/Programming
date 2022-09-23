class Solution {
    int CountBit(int n){
        return log2(n) + 1;
    }
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9+7;
        long int res = 0;
        for(int i=1;i<=n;i++){
            int bit = CountBit(i);
            res = ((res<<bit)%mod + i)%mod;
        }
        return res;
    }
};