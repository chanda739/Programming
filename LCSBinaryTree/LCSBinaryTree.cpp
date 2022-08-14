/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void lcphelper(TreeNode* A, int len, int value, int& ans) {
    if (A == nullptr)return;
    if (A->val == value)len++;
    else
        len = 1;
    ans = max(ans, len);
    lcphelper(A->left, len, A->val + 1, ans);
    lcphelper(A->right, len, A->val + 1, ans);
}
int Solution::solve(TreeNode* A) {
    if (A == nullptr)return 0;
    int ans = 0;
    lcphelper(A, 0, A->val, ans);
    return ans;
}