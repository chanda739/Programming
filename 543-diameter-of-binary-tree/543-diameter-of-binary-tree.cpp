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
    int diameter(TreeNode* root, int &length){
        if(root==nullptr)return -1;
        
        int l = diameter(root->left, length);
        int r = diameter(root->right, length);
        length = max(length, l+r+2);
        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int length = 0;
        diameter(root,length);
        return length;
    }
};