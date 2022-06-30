class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int avg = nums[l/2];
        int moves = 0;
        for(auto x: nums){
            moves += abs(avg - x);
        }
        return moves;
    }
};

/*
1 10 2 9
4 5  3 4

1 0 0 8 6
1 1 1 1 1
2 3 3 5 3
1 2 2 6 4
*/