class Solution {
public:
    vector<int> count(int n){
        vector<int> res(10);
        while(n>0){
            res[n%10]++;
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> res = count(n);
        for(int i=0;i<31;++i)
            if(res==count(1<<i))return true;
        return false;
    }
};