/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==nullptr)return {};
        vector<vector<int>> res;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            res.emplace_back();
            for(int i=q.size();i>=1;i--){
                Node* t = q.front();q.pop();
                res.back().push_back(t->val);
                for(Node* node: t->children)
                    q.push(node);
            }
        }
        return res;
    }
};