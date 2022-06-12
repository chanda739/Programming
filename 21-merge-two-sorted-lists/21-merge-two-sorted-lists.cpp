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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)
            return list2;
        if(list2==nullptr)
            return list1;
        ListNode* h3 = nullptr, *h1 = list1, *h2 = list2;
        if(h1->val <= h2->val){
            h3 = h1;
            h1 = h1->next;
        }
        else{
            h3 = h2;
            h2 = h2->next;
        }
        ListNode* l = h3;
        while(h1!=nullptr && h2!=nullptr){
            if(h1->val <= h2->val){
                l->next = h1;
                h1 = h1->next;
            }
            else{
                l->next = h2;
                h2 = h2->next;
            }
            l = l->next;
        }
        if(h1==nullptr){
            l->next = h2;
           // h1 = h1->next;
        }
        if(h2==nullptr){
            l->next = h1;
           // h2 = h2->next;
        }
        return h3;
    }
};