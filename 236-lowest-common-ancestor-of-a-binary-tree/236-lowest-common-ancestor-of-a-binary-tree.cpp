/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return root;
        if(root==p || root==q)return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        if(left!=nullptr && right!=nullptr)return root;
        
        return left!=nullptr?left:right;

    }
};

/*
TreeNode* find(TreeNode* root, TreeNode* p){
        if(root==nullptr)return root;
        if(root==p)return root;
        return find(root->left,p) || find(root->right,p);
    }
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr)return root;
        if(find(root,p)==nullptr || find(root,q)==nullptr){
            return nullptr;
        }
        return lowestCommonAncestor(root,p,q);
    }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==p || root==q)return root;
            TreeNode *left = lowestCommonAncestor(root->left,p,q);
            TreeNode *right = lowestCommonAncestor(root->right,p,q);
            if(left!=nullptr && right!=nullptr)return root;
            return left!=nullptr?left:right;
        }

*/
