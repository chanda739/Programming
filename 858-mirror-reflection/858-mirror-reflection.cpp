class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        while(p%2==0 && q%2==0){
            p/=2;q/=2;
        }
        return 1 - p%2 + q%2;
    }
};

/**
m*p==n*q
m = #room extension + 1
n = #reflection + 1

if m is odd and n is even => 2
if m is odd and n is odd => 1
if m is even and n is odd => 0
m and n both even not possible 
**/