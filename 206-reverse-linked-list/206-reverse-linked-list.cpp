/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode* h2 = nullptr, *t = head, *l = nullptr;
        while(t!=nullptr){
            l = t;
            t = t->next;
            l->next = h2;
            h2 = l;
        }
        return h2;
    }
};