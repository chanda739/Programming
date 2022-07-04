class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;//minheap
        for(int i=0;i<nums.size();i++){
            if(pq.empty())
                pq.push(nums[i]);
            else{
                if(pq.size()<k){
                    //cout<<pq.size()<<" ";
                    pq.push(nums[i]);
                }
                else if(pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                   // cout<<pq.size()<<" ";
                }
            }
        }
        return pq.top();
    }
};