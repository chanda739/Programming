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
    private:
        int dfs(TreeNode* root) 
        {
            if (!root) return 2;
            int left = dfs(root->left), right = dfs(root->right);
            if (left == 0 || right == 0) 
            {
                mCamera++;
                return 1;
            }
            return left == 1 || right == 1 ? 2 : 0;
        }
public:
    int mCamera = 0;
    int minCameraCover(TreeNode* root) 
    {
        if(dfs(root)<1)
            return 1 + mCamera;
        return mCamera;
    }


   /* int minCameraCover(TreeNode* root) {
        if(root==nullptr)return 0;
        if(root && root->left==nullptr && root->right==nullptr)return 1;
        int mCamera = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            TreeNode* curr = p.first;
            int level = p.second;
            if((level&1)==1){
                mCamera += q.size();
            }
            int size = q.size();
            while(size--)
            {
                if(curr->left)
                    q.push({curr->left,level+1});
                if(curr->right)
                    q.push({curr->right,level+1});
                q.pop();
            }
        }
        return mCamera;
    }
    */
};