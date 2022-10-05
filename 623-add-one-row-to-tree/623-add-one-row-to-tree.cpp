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
    void addNode(TreeNode* root, int val, int depth, int d){
        if(root==nullptr)return;
        if(depth==d-1){
            TreeNode* newNode = root->left;
            root->left = new TreeNode(val);
            root->left->left = newNode;
            newNode = root->right;
            root->right = new TreeNode(val);
            root->right->right = newNode;
            
        }else{
            addNode(root->left,val,depth+1,d);
            addNode(root->right,val,depth+1,d);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        addNode(root,val,1,depth);
        return root;
    }
};