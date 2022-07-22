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
        ListNode* temp = head, *h1 = head, *h2 = nullptr;
        while(h1!=nullptr){
            temp = h1;
            h1 = h1->next;
            temp->next = h2;
            h2 = temp;
        }
        return h2;
    }
};