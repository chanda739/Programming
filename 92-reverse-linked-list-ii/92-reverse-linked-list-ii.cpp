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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || left==right)return head;
        ListNode* temp = head, *prev = nullptr;
        int pos = 1;
        while(temp!=nullptr){
            if(pos==left)break;
            prev = temp;
            temp = temp->next;
            pos++;
        }
       pos--;
        ListNode* h1 = temp, *h3 = nullptr, *t;
        while(h1!=nullptr){
            t = h1;
            h1 = h1->next;
            t->next = h3;
            h3 = t;
            pos++;
            if(right==pos)break;
        }
        if(prev!=nullptr){
            prev->next = h3;  
        }
        if(temp!=nullptr)
            temp->next = h1;
       if(prev==nullptr)return h3;
        return head;
    }
};