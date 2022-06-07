class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=candies[0],i,l=candies.size();
        vector<bool> CountofCandies(l,false);
        for(i=1;i<l;i++){
            if(candies[i]>maxCandies)
                maxCandies = candies[i];
        }
        for(i=0;i<l;i++){
            if((candies[i]+extraCandies)>=maxCandies)
                CountofCandies[i]=true;
        }
        return CountofCandies;
    }
};