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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root!=nullptr || !st.empty()){
            if(root!=nullptr){
                st.push(root);
                root = root->left;
            }else{
                TreeNode* curr = st.top();
                res.push_back(curr->val);
                st.pop();
                root = curr->right;
            }
        }
        return res;
    }
};