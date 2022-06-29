class Solution {
public:
    static bool comp(vector<int> &a, vector<int>&b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),comp);
        vector<vector<int>> res;
        for(auto p : people)
            res.insert(res.begin() + p[1], p);
        return res;
    }
};
/*
7 4 7 5 6 5
0 4 1 0 1 2

7 7 6 5 5 4
0 1 1 0 2 4

*/