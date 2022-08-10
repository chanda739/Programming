/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* sortedArrayToBSTUtil(vector<int> nums, int l, int r){
        if(l>=r)return nullptr;
        int mid=(l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums,l,mid);
        root->right = sortedArrayToBSTUtil(nums,mid+1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return nullptr;
        return sortedArrayToBSTUtil(nums, 0,n);
    }
};