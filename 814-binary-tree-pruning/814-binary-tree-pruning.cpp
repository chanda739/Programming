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
    bool SubtreeContainsOne(TreeNode* root){
        if(root==nullptr)return false;
        
        bool leftContainsOne = SubtreeContainsOne(root->left);
        bool rightContainsOne = SubtreeContainsOne(root->right);
        
        if(!leftContainsOne)root->left = nullptr;
        if(!rightContainsOne)root->right = nullptr;
        
        return root->val==1 or leftContainsOne or rightContainsOne;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return SubtreeContainsOne(root)?root:nullptr;
    }
};