class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int grp = 0, size = 0, n = grades.size();
        while(grp+size+1<=n){
            size+=(++grp);
        }
        return grp;
    }
};