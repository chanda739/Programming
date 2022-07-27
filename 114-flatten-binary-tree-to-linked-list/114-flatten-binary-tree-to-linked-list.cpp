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
    void flatten(TreeNode* root) {
        //Base case
        if(root==nullptr)return;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        //Flatten left subtree
        flatten(left);
        //Flatten right subtree
        flatten(right);
        
        root->right = left;
        TreeNode* curr = root;
        while(curr->right!=nullptr)
            curr = curr->right;
        curr->right = right;
    }
};