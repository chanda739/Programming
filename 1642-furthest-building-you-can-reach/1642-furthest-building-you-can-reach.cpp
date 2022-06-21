class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int jumps = 0,largestjump = 0,res,i;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(i = 1;i<heights.size();i++){
            if(heights[i]<=heights[i-1])
                continue;
            pq.push(heights[i] - heights[i-1]);
            if(pq.size()>ladders){
                jumps += pq.top();
                pq.pop();
                //ladders--;
            }
            if(jumps>bricks){
                return i-1;
            }
        }
        return heights.size()-1;
    }
};

/* 10 2
0,1 ,2,3,4,5 ,6, 7,8
4,12,2,7,3,18,20,3,19
8,c ,5,c,15,2,c ,c,
8-13-(13>10)-3-18-3
0,8,0,15,

*/