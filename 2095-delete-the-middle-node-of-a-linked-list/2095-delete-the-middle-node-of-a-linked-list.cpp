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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==nullptr)return nullptr;
        int count = 0;
        ListNode* slow = head, *fast = head;
        while(slow!=nullptr){
            count++;
            slow = slow->next;
        }
        int mid = count/2;
        for(int i=0;i<mid-1;i++)fast = fast->next;
        
        fast->next = fast->next->next;
        return head;
    }
};