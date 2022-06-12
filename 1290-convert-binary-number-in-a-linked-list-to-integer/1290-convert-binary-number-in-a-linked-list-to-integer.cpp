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
    int getSize(ListNode* head){
        int count  = 0;
        while(head!=nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
    int getDecimalValue(ListNode* head) {
        int size = getSize(head);
        ListNode* temp = head;
        int decimal = 0;
        while(temp!=nullptr){
            decimal += (temp->val) * pow(2,size-1);
            size = size-1;
            temp = temp->next;
        }
        return decimal;
    }
};