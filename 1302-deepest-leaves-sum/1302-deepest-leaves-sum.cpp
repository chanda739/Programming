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
   void LeavesSum(TreeNode* root, int level, int &sum,int &ml){
        if(root==nullptr)
            return;
        if(ml<level){
            ml = level;
            sum = 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            if(level==ml)sum+=root->val;
        }
        LeavesSum(root->left, level+1,sum,ml);
        LeavesSum(root->right, level+1,sum,ml);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0,level = 0,ml=0;
        LeavesSum(root,level,sum,ml);
        return sum;
    }
};