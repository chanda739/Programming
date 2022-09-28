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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0,i=0;
        ListNode* temp;
        ListNode* start = head;
        ListNode* end = head;
        while(i<n){
            //Increment head(end) pointer till nth node from beginning
            if(end->next==nullptr){
                
                if(i==(n-1)){
                    temp = head;
                    head= head->next;
                    delete temp;
                }
                return head;
            }
            end = end->next;
            i++;
        }
        
        //once at nth node, initialize start ptr and increment both start and end until end is not null
        while(end->next!=nullptr){
            start = start->next;
            end = end->next;
        }
        //start is at n-1 th node, update start.next and then delete start.next
        temp = start->next;
        start ->next = start->next->next;
        delete temp;
        return head;
    }
};