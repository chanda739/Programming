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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr ||head->next==nullptr)return head;
        ListNode* h1 = new ListNode(-1);
        ListNode* t1 = new ListNode(-1);
        ListNode* h = h1, *t = t1;
        while(head!=nullptr){
            if(head->val < x){
                h->next = head;
                h = h->next;
            }else{
                t->next = head;
                t = t->next;
            }
            head = head->next;
        }
        h->next = t1->next;
        t->next = nullptr;
        return h1->next;
    }
};