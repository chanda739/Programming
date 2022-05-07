class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int m = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<m)
                return true;
            while(!st.empty()&&st.top()<nums[i]){
                m = st.top();st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
        
        /*
        //Two pointer approach(fail for n>= 10^5)
        int m = nums[0];
        for(int j = 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                if(nums[k] > m && nums[j] > nums[k]) return true;
                m = min(m, nums[j]);
            }
        }
        return false;
    }
    */
    /*
        //Three pointer approach(fail for n>= 10^3)
        for(int i = 0;i < nums.size(); i++){
            for(int j = i+1; j < nums.size() - 1; j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[k] > nums[i] && nums[j] > nums[k]) return true;
                }
            }
        }
        return false;
    }
    */
};
