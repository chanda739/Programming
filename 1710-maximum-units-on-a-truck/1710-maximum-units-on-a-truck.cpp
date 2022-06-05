class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]> b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int sum = 0,size = truckSize;
        
        for(int i=0;i<n;i++){
            if(boxTypes[i][0]<size){
                sum += (boxTypes[i][1]*boxTypes[i][0]);
                size = size - boxTypes[i][0];
            }
            else{
                sum += (size*boxTypes[i][1]);
                size = 0;
            }
        }
        return sum;
    }
};