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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==nullptr)return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            long sum = 0,count = 0;
            queue<TreeNode*> tmp;
            while(!q.empty()){
                TreeNode* t = q.front();q.pop();
                sum+=t->val;
                count++;
                if(t->left!=nullptr)tmp.push(t->left);
                if(t->right!=nullptr)tmp.push(t->right);
            }
            q = tmp;
            res.push_back(1.0*sum/count);
        }
        return res;
    }
};