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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res; vector<int> v;
        if(root==nullptr)return res;
        queue<TreeNode*> q;
        q.push(root);q.push(nullptr);
        while(q.size()>1){
            TreeNode* f = q.front();q.pop();
            if(f==nullptr){
                res.push_back(v);
                v.clear();
                q.push(nullptr);
            }else{
                v.push_back(f->val);
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
        }
        res.push_back(v);
        return res;
    }
};