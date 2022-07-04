class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = ratings.size();
        vector<int> left(l,0), right(l,0);
        left[0] = 1;
        for(int i=1;i<l;i++){
            if(ratings[i]>ratings[i-1])
                left[i] = left[i-1] + 1;
            else
                left[i] = 1;
        }
        right[l-1] = 1;
        for(int i=l-2;i>=0;i--){
            if(ratings[i]>ratings[i+1])
                right[i] = right[i+1] + 1;
            else
                right[i] = 1;
        }
        int candy = 0;
        for(int i=0;i<l;i++){
            candy += max(left[i], right[i]);
        }
        left.clear();
        right.clear();
        return candy;
    }
};