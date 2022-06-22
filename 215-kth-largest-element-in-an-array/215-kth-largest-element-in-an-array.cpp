class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mHeap;
        
        for(int i=0;i<nums.size();i++){
            mHeap.push(nums[i]);
            if(mHeap.size()>k){
                //cout<<mHeap.top()<<" ";
                mHeap.pop();
            }
        }
        if(mHeap.size()>k)mHeap.pop();
        return mHeap.top();
    }
};

/*
3,2,1,5,6,4
6,5,4,3,2,1
*/