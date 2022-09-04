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
    map<int, map<int, multiset<int>>> mp;
    vector<vector<int>> res;

    void traversal(TreeNode* root, int x, int y){
        if(root==nullptr)return;
        
        mp[x][y].insert(root->val);
        traversal(root->left,x-1,y+1);
        traversal(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traversal(root,0,0);
        
        for (auto itx = mp.begin(); itx != mp.end(); ++itx) {
          res.push_back(vector<int>());
          for (auto ity = itx->second.begin(); ity != itx->second.end(); ++ity) {
              res.back().insert(end(res.back()), begin(ity->second), end(ity->second));
          }
        }
        return res;
    }
};