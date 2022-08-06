class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int score = 0,maxScore = 0;
        for(int value:values){
            maxScore = max(maxScore, value+score);
            score = max(score,value) - 1;            
        }
        return maxScore;
        /*
        //TLE
        int i,j,maxScore = 0;
        for(i=0;i<values.size();i++){
            for(j=i+1;j<values.size();++j){
                maxScore = max(maxScore, values[i]+values[j]+i-j);
            }
        }
        return maxScore;
        */
    }
};