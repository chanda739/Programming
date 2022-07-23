class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0,pos=0;
        for(pos=0;pos<32;pos++){
           // if(((x>>pos)^(y>>pos))==1)
                distance+=(((x>>pos)&1)^((y>>pos)&1));
        }
        return distance;
    }
};