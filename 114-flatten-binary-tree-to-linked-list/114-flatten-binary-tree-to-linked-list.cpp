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
    void flatten(TreeNode* root) {
        if(root==nullptr)return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = nullptr;
        
        flatten(left);
        flatten(right);
        root->right = left;
        TreeNode* curr = root;
        while(curr->right!=nullptr)
            curr = curr->right;
        curr->right = right;
    }
};

/*
if(root==nullptr)return;
        if(root->left==nullptr && root->right==nullptr)
            return;
        // if(root->left==nullptr)
        //     flatten(root->right);
        TreeNode* temp = root, *prev = nullptr;
        while(temp->left!=nullptr){
            prev = temp;
            temp = temp->left;
        }
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        if(temp->right==nullptr){
            if(prev!=nullptr){
                temp->right = prev->right;
                prev->right = nullptr;
            }
        }
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        if(temp->right != root->right)
            temp->right = root->right;
        if(root->left!=nullptr)
         {   root->right = root->left;
            root->left = nullptr;
         }
        if(root->left==nullptr)
            flatten(root->right);

*/