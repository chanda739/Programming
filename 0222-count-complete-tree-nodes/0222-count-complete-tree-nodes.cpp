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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int l = 1, r = 1;
        TreeNode *rightp = root, *leftp = root;
        while (leftp = leftp->left) l++;
        while (rightp = rightp->right) r++;
        
        if (l == r) return pow(2, l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};