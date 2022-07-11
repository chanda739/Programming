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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)return res;
        
        queue<TreeNode*> q;
        q.push(root);q.push(nullptr);
        while(q.size()>1){
            TreeNode* f = q.front();q.pop();
                res.push_back(f->val);
            int size = q.size();
            while(size){
                if(f->right!=nullptr)q.push(f->right);
                if(f->left!=nullptr)q.push(f->left);
                size--;
                f = q.front();q.pop();
            }
            //q.pop();
            q.push(nullptr);
        }
        return res;
    }
};