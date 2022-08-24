class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1)return false;
        while(n!=0 && n%3==0)n/=3;
        return n==1;
    }
};

/*
0123456
1 2 4 8 16 32 64 128
3 9 27 81 243
*/