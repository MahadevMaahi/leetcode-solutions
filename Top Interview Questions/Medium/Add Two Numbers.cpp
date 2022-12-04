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

 /*
    
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        ListNode *prev = nullptr, *head, *p, *q;
        head = l1; p = l1; q = l2;
        int sum = 0, carry = 0;
        while(p != nullptr && q != nullptr) {
            prev = p;
            sum = p->val + q->val + carry;
            p-> val = sum % 10;
            carry = sum / 10;
            p = p->next;
            q = q->next;
        }
        if(p == nullptr) {
            p = q;
            prev->next = q;
        }
        while(p != nullptr) {
            prev = p;
            sum = p->val + carry;
            p->val = sum % 10;
            carry = sum / 10;
            p = p->next;
        }
        if(carry != 0) {
            prev->next = new ListNode(carry)
        }
        return head;
    }
};