// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n,m;
        while(lo<=hi){
            m = lo + (hi-lo)/2;
            if(isBadVersion(m)==true && isBadVersion(m-1)==false)return m;
            else if(isBadVersion(m)==false)lo = m+1;
            else hi = m-1;
        }
        return m;
    }
};