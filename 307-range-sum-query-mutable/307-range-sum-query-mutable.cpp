class NumArray {
    //vector<int> A;
    vector<int> tree;
    int n;
    void buildTree(vector<int> nums){
        for(int i=n,j=0;i<2*n;i++,j++){
            tree[i] = nums[j];
        }
        for(int i=n-1;i>0;i--){
            tree[i] = tree[i*2] + tree[i*2+1];
        }
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
            n = nums.size();
            tree.resize(2*n);
            buildTree(nums);
        }
       // A.resize(nums.size());
       //  std::copy(std::begin(nums), std::end(nums), std::begin(A));
    }
    
    void update(int index, int val) {
       // A[index] = val;
        index+=n;
        tree[index] = val;
        while(index>0){
            int left = index;
            int right = index;
            if((index&1)==0)right = index + 1;
            else left = index - 1;
            tree[index/2] = tree[left] + tree[right];
            index/=2;
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        // while(left<=right){
        //     sum = A[left];
        //     left++;
        // }
        left+=n;right+=n;
        while(left<=right){
            if((left&1)==1){
                sum+=tree[left];left++;
            }
            if((right&1)==0){
                sum+=tree[right];right--;
            }
            right/=2;
            left/=2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */