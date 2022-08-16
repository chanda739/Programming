class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        set<int> st;
        for(int x:nums)
            if(x>0)st.insert(x);
        return st.size();
        /**
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int x:nums){
            if(x>0)
                pq.push(x);
        }
        
        int count = 0, sum = 0;
        while(pq.size()>0){
            int t = pq.top();
            pq.pop();
            sum = sum + (t-sum);count++;
            while(pq.size()>0){
                if(sum==pq.top())pq.pop();
                else break;
            }
        }
       
        return count;
        ***/
    }
};

/**
[1,5,0,3,5]
set = [1,5,3]
def minimumOperations(self, nums):
        return len(set(num for num in nums if num > 0))
**/