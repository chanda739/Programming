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
public:
    int PS(TreeNode* root, int &ans){
        if(root==nullptr)return 0;
        int l = PS(root->left,ans); l = max(l,0);
        int r = PS(root->right,ans); r = max(r,0);
        ans = max(ans, l+r+root->val);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        PS(root,ans);
        return ans;
    }
};