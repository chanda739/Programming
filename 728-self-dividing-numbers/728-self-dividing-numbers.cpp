class Solution {
    bool isSelfDividing(int n){
        int t = n;
        while(t>0){
            int x = t%10;
            if(x==0 || n%x!=0)return false;
            t = t/10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i))res.push_back(i);
        }
        return res;
    }
};