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
    int sum = 0;
    int deepestLevel = 0;
    void DeepestSumLeaves(TreeNode* root, int level){
        if(root==nullptr)
            return;
        if(level > deepestLevel){
            sum = 0;
            deepestLevel = level;
        }
        if(level == deepestLevel){
            sum+=root->val;
        }
       DeepestSumLeaves(root->left,level+1);
       DeepestSumLeaves(root->right,level+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr)
            return 0;
        DeepestSumLeaves(root,0);
        return sum;
    }
};