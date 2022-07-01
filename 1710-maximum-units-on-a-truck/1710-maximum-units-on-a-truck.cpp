class Solution {
public:
    static bool comp(vector<int> & a, vector<int>& b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int mUnit = 0;
        for(int i=0;i<boxTypes.size();i++){
            if(truckSize==0)return mUnit;
            if(truckSize>=boxTypes[i][0]){
                mUnit += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                mUnit += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
        }
        return mUnit;
    }
};

/**
1 1 1
3 2 1
*/