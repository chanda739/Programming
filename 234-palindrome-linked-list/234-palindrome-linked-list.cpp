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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return true;
        ListNode* slow = head, *fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* centre = slow;
        ListNode *h1 = slow->next,*t=nullptr,*h2=nullptr;
        while(h1!=nullptr){
            t = h1;
            h1 = h1->next;
            t->next = h2;
            h2 = t;
        }
        centre->next = nullptr;
        while(head!=nullptr && h2!=nullptr){
            if(head->val==h2->val){
                head = head->next;
                h2 = h2->next;
            }else{
               return false;
            }
        }
        if((head!=nullptr && h2==nullptr) || (head==nullptr && h2==nullptr))return true;
        return false;
    }
};