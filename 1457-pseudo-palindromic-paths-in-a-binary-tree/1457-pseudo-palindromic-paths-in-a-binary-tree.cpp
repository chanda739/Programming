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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        
        stack<pair<TreeNode*, int>> st;
        st.push({root,0});
        while(!st.empty()){
            pair<TreeNode*, int> p = st.top(); st.pop();
            TreeNode* node = p.first;
            int t = p.second;
            if(node!=nullptr){
                t = t^(1<<node->val);
                if(node->left==nullptr && node->right==nullptr){
                    if((t &(t-1))==0)res++;
                }else{
                    st.push({node->left,t});
                    st.push({node->right,t});
                }
            }
        }
        return res;
    }
};
/***
1. Find all possible root to leaf paths
2. then for each path, check if rearranging makes it palindrome.
3. Count all such paths.
*/