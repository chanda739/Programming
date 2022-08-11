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
    bool isValidBSTUtil(TreeNode* root, long mn, long mx){
        if(root==nullptr)return true;
        if(root->val < mn || root->val > mx)
            return false;
        return isValidBSTUtil(root->left, mn, (long)root->val - 1) && 
                    isValidBSTUtil(root->right, (long)root->val + 1, mx);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        long mn = INT_MIN,mx = INT_MAX;
        return isValidBSTUtil(root, mn, mx);
    }
};
//Cornet case: 
//[-2147483648,-2147483648]->false