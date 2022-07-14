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
    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie, unordered_map<int,int> &index){
        if(is>ie)return nullptr;
        
        int id = index[preorder[ps]];
        int len = id - is;
        TreeNode* root = new TreeNode(preorder[ps]);
        root->left = buildTreeUtil(preorder, inorder, ps+1, ps+len, is, id-1, index);
        root->right = buildTreeUtil(preorder, inorder, ps+len+1, pe, id+1, ie, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre1 = preorder.size(), in1 = inorder.size();
        if(pre1!=in1)return nullptr;
        TreeNode* root;
        unordered_map<int, int> index;
        for(int i=0;i<in1;i++){
            index[inorder[i]] = i;
        }
        int ps = 0, pe = pre1-1, is = 0, ie = in1 - 1;
        return buildTreeUtil(preorder, inorder, ps, pe, is, ie, index);
    }
};