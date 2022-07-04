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
    ListNode* reverse1stKLink(ListNode* head, int k){
        ListNode* h1 = head, *t = nullptr, *h3 = nullptr;
        while(k>0 && h1!=nullptr){
            t = h1;
            h1 = h1->next;
            t->next = h3;
            h3 = t;
            k--;
        }
        return h3;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==1)return head;
        ListNode* curr = head;
        int count=0;
        while(count<k){
            if(curr==NULL)return head;
            curr = curr->next;
            count++;
        }
        ListNode* res = reverse1stKLink(head,k);
        head->next = reverseKGroup(curr,k);
        return res;
    }
};