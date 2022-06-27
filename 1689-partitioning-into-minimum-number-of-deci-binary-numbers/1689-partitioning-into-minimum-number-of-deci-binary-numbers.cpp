class Solution {
public:
    int minPartitions(string n) {
        int length = n.size();
        int mdeci = 0;
        for(int i=0;i<length;i++){
            mdeci = max(mdeci, n[i]-'0');
            if(mdeci==9)return mdeci;
        }
        return mdeci;
    }
};

/*
0 1
10 11
100 101 110 111
1000 1001 1010 1100 1011 1101 1110 1111


*/