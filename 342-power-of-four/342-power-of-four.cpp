class Solution {
public:
    bool isPowerOfFour(int n) {
        int x = 0,count0 = 0,count1 = 0;
        while(n>0){
            if((n&1)==1)
                count1++;
            else
                count0++;
            n = n>>1;
        }
        return count1==1&&count0%2==0?true:false;
    }
};
/*
256 128 64 32 16 8 4 2 1
8   7   6  5  4  3 2 1 0
*/