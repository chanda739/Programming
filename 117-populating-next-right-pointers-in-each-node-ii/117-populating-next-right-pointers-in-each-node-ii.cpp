/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* nextChild(Node* root){
        while(root!=nullptr){
            if(root->left!=nullptr)
                return root->left;
            if(root->right!=nullptr)
                return root->right;
            root = root->next;
        }
        return root;
    }
    void fillNextPointer(Node* root){
        while(root!=nullptr){
            Node* temp = root;
            while(temp!=nullptr){
                if(temp->left!=nullptr){
                    if(temp->right!=nullptr)
                        temp->left->next = temp->right;
                    else
                        temp->left->next = nextChild(temp->next);
                }
                if(temp->right!=nullptr){
                    temp->right->next = nextChild(temp->next);
                }
                temp = temp->next;
            }
            root = nextChild(root);
        }
    }
    Node* connect(Node* root) {
        fillNextPointer(root);
        return root;
    }
};