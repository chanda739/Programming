class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = cardPoints.size();
        int score = 0,mScore = 0;
        for(int i=0;i<k;i++){
            score += cardPoints[i];
        }
        mScore = score;
        for(int i=0,j=k-1;j>=0;j--){
            score -= cardPoints[j];
            score += cardPoints[l-1-i];
            i++;
            mScore = max(mScore, score);
        }
        return mScore;
    }
};