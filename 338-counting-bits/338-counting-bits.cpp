class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        /*
        Two cases
        1. if x is even: count of set bit in x is same as count of count of set bit in x/2
        2. if x is odd: then count of set bit in x will be 1 more than count of set bit in x/2 bcz of LSB set in x 
        */
        for(int i=1;i<=n;i++){
            res[i] = res[i/2] + (i%2);
        }
        return res;
    }
};

/* O(nlogn) solution
    //function to count set bit in each integer in log n
    int countSetBit(int n){
        int count =0;
        while(n>0){
            if(n&1)
                count++;
            n=n>>1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        //iterate from 0 to n which will take O(n), overall time complexity O(nlogn)
        for(int i=0;i<=n;i++){
            res.push_back(countSetBit(i));
        }
        return res;
    }
*/