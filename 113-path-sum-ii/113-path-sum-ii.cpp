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
    void hasPathSum(TreeNode* root, int targetSum,vector<vector<int>> &res,vector<int> &v) {
        if(root==nullptr)return;
        v.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && root->val==targetSum){
            res.push_back(v);
        }
        hasPathSum(root->left,targetSum-root->val,res,v);
        hasPathSum(root->right,targetSum-root->val,res,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        hasPathSum(root,targetSum,res,v);
        return res;
    }
};